#!/bin/bash

# Set the base directory
BASE_DIR="dataset"
OUTPUT_FILE="output.csv"

# Check if ROPgadget is installed
if ! command -v ROPgadget &> /dev/null; then
    echo "ROPgadget could not be found. Please install it first."
    exit 1
fi

# Initialize the CSV file with headers
echo "Purpose,Structure,SourceCodeSize,MainCppSize,OptimizationLevel,BinarySize,Linkage,UniqueGadgets,ROPgadgetTime" > "$OUTPUT_FILE"

# Get the total number of files to process
total_files=$(find "$BASE_DIR" -type f -name "main-*.out" | wc -l)
current_file=0

# Find and process all files matching the pattern
find "$BASE_DIR" -type f -name "main-*.out" | while read -r binary_file; do
    current_file=$((current_file + 1))
    echo "Processing file $current_file of $total_files: $binary_file"

    # Extract details from the file path
    relative_path="${binary_file#$BASE_DIR/}"
    purpose=$(echo "$relative_path" | cut -d'/' -f1)
    structure=$(echo "$relative_path" | cut -d'/' -f2)
    source_code_size=$(echo "$relative_path" | cut -d'/' -f3)
    optimization_level=$(basename "$binary_file" | grep -oP "main-\K(O[0-3])")
    linkage=$(basename "$binary_file" | grep -oP "(dynamic|static)")

    # Get the size of main.cpp in the directory
    main_cpp_path="$(dirname "$binary_file")/main.cpp"
    if [ -f "$main_cpp_path" ]; then
        main_cpp_size=$(stat --format="%s" "$main_cpp_path")
    else
        main_cpp_size="0" # If main.cpp is missing
    fi

    # Get the size of the binary file
    binary_size=$(stat --format="%s" "$binary_file")

    # Run ROPgadget and measure execution time
    start_time=$(date +%s%N)
    output=$(ROPgadget --binary "$binary_file")
    end_time=$(date +%s%N)

    # Calculate the duration in seconds with milliseconds precision
    duration=$(echo "scale=3; ($end_time - $start_time)/1000000000" | bc)

    # Extract the total number of unique gadgets
    unique_gadgets=$(echo "$output" | grep "Unique gadgets found:" | awk '{print $4}')
    if [ -z "$unique_gadgets" ]; then
        unique_gadgets="0" # If no gadgets are found
    fi

    # Append the data to the CSV file
    echo "$purpose,$structure,$source_code_size,$main_cpp_size,$optimization_level,$binary_size,$linkage,$unique_gadgets,$duration" >> "$OUTPUT_FILE"
done

echo "Processing complete. Results saved to $OUTPUT_FILE."

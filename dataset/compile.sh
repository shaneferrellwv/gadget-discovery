#!/bin/bash

# Base directories
purposes=("arithmetic" "fileio" "string")
structures=("dense" "sparse")
sizes=("small" "medium" "large")
optimizations=("-O0" "-O1" "-O2" "-O3")

for purpose in "${purposes[@]}"; do
    for structure in "${structures[@]}"; do
        for size in "${sizes[@]}"; do
            cpp_file="$purpose/$structure/$size/main.cpp"
            
            if [[ -f "$cpp_file" ]]; then
                for opt in "${optimizations[@]}"; do
                    # Compile the file using gcc with the current optimization level
                    output="$purpose/$structure/$size/main${opt}.out"
                    echo "Compiling $cpp_file with $opt"
                    gcc "$cpp_file" "$opt" -o "$output"
                done
            else
                echo "File $cpp_file does not exist!"
            fi
        done
    done
done

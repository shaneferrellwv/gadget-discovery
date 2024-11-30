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
                    # Dynamic linking (default)
                    output_dynamic="$purpose/$structure/$size/main${opt}_dynamic.out"
                    echo "Compiling $cpp_file with $opt (dynamic linking)"
                    gcc "$cpp_file" "$opt" -o "$output_dynamic"

                    # Static linking
                    output_static="$purpose/$structure/$size/main${opt}_static.out"
                    echo "Compiling $cpp_file with $opt (static linking)"
                    gcc "$cpp_file" "$opt" -static -o "$output_static"
                done
            else
                echo "File $cpp_file does not exist!"
            fi
        done
    done
done

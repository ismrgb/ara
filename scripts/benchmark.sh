#!/bin/bash

# Python in use
PYTHON=python3

# Include Ara's configuration
if [ -z ${config} ]; then
    if [ -z ${ARA_CONFIGURATION} ]; then
        config=default
    else
        config=${ARA_CONFIGURATION}
    fi
fi

tmpscript=`mktemp`
sed "s/ ?= /=/g" config/${config}.mk > $tmpscript
source ${tmpscript}

##########
## AXPY ##
##########

############
## MATMUL ##
############

# Measure the runtime of the following kernels
for kernel in imatmul fmatmul; do

    # Log the performance results
    > ${kernel}_${nr_lanes}.benchmark

    # Measure the following matrix sizes
    for size in 4 8 16 32 64 128; do

        tempfile=`mktemp`

        DEFINES="-DSIZE=$size -D${kernel^^}=1" \
               make -C apps/ bin/benchmarks
        make -C hardware/ simv app=benchmarks > $tempfile

        # Extract the performance
        cat $tempfile | grep "\[performance\]" | cut -d: -f2 >> ${kernel}_${nr_lanes}.benchmark

    done
done

############
## CONV2D ##
############

# Measure the runtime of the following kernels
for kernel in iconv2d; do

    # Log the performance results
    > ${kernel}_${nr_lanes}.benchmark

    # Measure the following matrix and filter sizes
    # The input image is also padded, and the max vl is 128
    # MAXVL_M2_64b - F_MAX + 1 = 128 - 7 + 1 = 122 is the max number of elements
    # Actually 120, since it must be divible by 4
    for msize in 4 8 16 32 64 112; do
        for fsize in 3 5 7; do
            tempfile=`mktemp`

            # Generate the correct matrix and filter
            ${PYTHON} apps/$kernel/script/gen_data.py > apps/benchmarks/data/data.S $msize $fsize

            DEFINES="-D${kernel^^}=1" \
                   make -C apps/ bin/benchmarks
            make -C hardware/ simv app=benchmarks > $tempfile

            # Extract the performance
            cat $tempfile | grep "\[performance\]" | cut -d: -f2 >> ${kernel}_${nr_lanes}.benchmark

        done
    done
done

##############
## JACOBI2D ##
##############

#############
## DROPOUT ##
#############

##############
## ROIALIGN ##
##############

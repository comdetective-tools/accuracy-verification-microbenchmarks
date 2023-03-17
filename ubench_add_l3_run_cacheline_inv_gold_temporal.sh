#! /bin/bash

ReuseTracker_path=/home/msasongko17/reusetracker/hpctoolkit-bin

HPCRUN_WP_REUSE_PROFILE_TYPE="TEMPORAL" HPCRUN_PROFILE_L3=true HPCRUN_WP_REUSE_BIN_SCHEME=4000,2 HPCRUN_WP_CACHELINE_INVALIDATION=true OMP_NUM_THREADS=32 HPCRUN_THREAD_LOCALITY_MAPPING=0%2%4%6%8%10%12%14%16%18%20%22%24%26%28%30#1%3%5%7%9%11%13%15%17%19%21%23%25%27%29%31 /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" $ReuseTracker_path/bin/hpcrun --mapping 0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31 -e WP_REUSETRACKER -e MEM_LOAD_RETIRED.L2_MISS@10000 -e MEM_INST_RETIRED.ALL_STORES@100000 -o ubench_add_l3_output write-volume/ubench_add -n 32 -s 1.0 -f 0.0 -i 100000000 2>&1 | tee ubench_add_reusetracker_log

#-e MEM_UOPS_RETIRED:ALL_STORES@100000
#-e MEM_LOAD_UOPS_RETIRED.L2_MISS@100000

TRACE_FILE=$(ls -lt | grep reuse.hpcrun | awk '{print $9}')

cat overhead.tmp | tee -a $TRACE_FILE >/dev/null

mkdir ubench_add_rd_l3_output

mv *hpcrun ubench_add_rd_l3_output

$ReuseTracker_path/bin/hpcstruct write-volume/ubench_add

$ReuseTracker_path/bin/hpcprof -S ./ubench_add.hpcstruct -o ubench_add_l3_database ubench_add_l3_output

mv ubench_add.hpcstruct ubench_add_rd_l3_output

mv ubench_add_l3_database ubench_add_rd_l3_output

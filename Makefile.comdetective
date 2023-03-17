ComDetective_bin=/mnt/data/home/msasongko17/cross-hardware-research/with_adamant/hpctoolkit-bin
perf_bin=/mnt/data/home/msasongko17/linux/tools/perf

sc_results: all_rfo_write volume_write_verification false_sharing_add_intra_socket_8_threads read_write p2p

add_volume_results: all_rfo_add volume_add_verification

exchg_volume_results: all_rfo_exchg volume_exchg_verification

add_write_results: volume_add_verification volume_write_verification

load_store_quick_test: volume_add_inter_socket_2_threads volume_add_inter_socket_16_threads volume_add_intra_socket_2_threads volume_add_intra_socket_8_threads

store_quick_test: volume_write_inter_socket_2_threads volume_write_inter_socket_16_threads volume_write_intra_socket_2_threads volume_write_intra_socket_8_threads

all_rfo_write: all_rfo_write_intra_socket all_rfo_write_inter_socket

all_rfo_write_intra_socket: all_rfo_write_intra_socket_2_threads all_rfo_write_intra_socket_4_threads all_rfo_write_intra_socket_8_threads all_rfo_write_intra_socket_16_threads

get_polynomial: all_all_rfo_write_intra_socket all_all_rfo_write_inter_socket all_volume_write_intra_socket all_volume_write_inter_socket

all_volume_comdetective: all_volume_write_intra_socket all_volume_write_inter_socket

all_all_rfo_write_intra_socket: all_rfo_write_intra_socket_2_threads all_rfo_write_intra_socket_3_threads all_rfo_write_intra_socket_4_threads all_rfo_write_intra_socket_5_threads all_rfo_write_intra_socket_6_threads all_rfo_write_intra_socket_7_threads all_rfo_write_intra_socket_8_threads

all_rfo_write_intra_socket_2_threads: metric_extractor_install volume_install all_rfo_write_intra_socket_run_2_threads all_rfo_write_intra_socket_extract_metrics_2_threads

all_rfo_write_intra_socket_3_threads: metric_extractor_install volume_install all_rfo_write_intra_socket_run_3_threads all_rfo_write_intra_socket_extract_metrics_3_threads

all_rfo_write_intra_socket_4_threads: metric_extractor_install volume_install all_rfo_write_intra_socket_run_4_threads all_rfo_write_intra_socket_extract_metrics_4_threads

all_rfo_write_intra_socket_5_threads: metric_extractor_install volume_install all_rfo_write_intra_socket_run_5_threads all_rfo_write_intra_socket_extract_metrics_5_threads

all_rfo_write_intra_socket_6_threads: metric_extractor_install volume_install all_rfo_write_intra_socket_run_6_threads all_rfo_write_intra_socket_extract_metrics_6_threads

all_rfo_write_intra_socket_7_threads: metric_extractor_install volume_install all_rfo_write_intra_socket_run_7_threads all_rfo_write_intra_socket_extract_metrics_7_threads

all_rfo_write_intra_socket_8_threads: metric_extractor_install volume_install all_rfo_write_intra_socket_run_8_threads all_rfo_write_intra_socket_extract_metrics_8_threads

all_rfo_write_intra_socket_16_threads: metric_extractor_install volume_install all_rfo_write_intra_socket_run_16_threads all_rfo_write_intra_socket_extract_metrics_16_threads

all_rfo_write_intra_socket_run_2_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_write_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 1" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_write -n 2 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_write_intra_socket_extract_metrics_2_threads:
	dump_file="all_rfo_write_intra_socket_2_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

all_rfo_write_intra_socket_run_3_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_write_intra_socket_3_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 1 2" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_write -n 3 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_write_intra_socket_extract_metrics_3_threads:
	dump_file="all_rfo_write_intra_socket_3_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_intra_socket_3_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_intra_socket_3_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_intra_socket_3_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

all_rfo_write_intra_socket_run_4_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_write_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 1 2 3" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_write -n 4 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_write_intra_socket_extract_metrics_4_threads:
	dump_file="all_rfo_write_intra_socket_4_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

all_rfo_write_intra_socket_run_5_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_write_intra_socket_5_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 1 2 3 4" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_write -n 5 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_write_intra_socket_extract_metrics_5_threads:
	dump_file="all_rfo_write_intra_socket_5_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_intra_socket_5_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_intra_socket_5_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_intra_socket_5_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

all_rfo_write_intra_socket_run_6_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_write_intra_socket_6_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 1 2 3 4 5" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_write -n 6 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_write_intra_socket_extract_metrics_6_threads:
	dump_file="all_rfo_write_intra_socket_6_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_intra_socket_6_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_intra_socket_6_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_intra_socket_6_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

all_rfo_write_intra_socket_run_7_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_write_intra_socket_7_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 1 2 3 4 5 6" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_write -n 7 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_write_intra_socket_extract_metrics_7_threads:
	dump_file="all_rfo_write_intra_socket_7_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_intra_socket_7_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_intra_socket_7_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_intra_socket_7_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

all_rfo_write_intra_socket_run_8_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_write_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 1 2 3 4 5 6 7" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_write -n 8 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_write_intra_socket_extract_metrics_8_threads:
	dump_file="all_rfo_write_intra_socket_8_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

all_rfo_write_intra_socket_run_16_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_write_intra_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 1 2 3 4 5 6 7 8 9 20 21 22 23 24 25" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_write -n 16 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_write_intra_socket_extract_metrics_16_threads:
	dump_file="all_rfo_write_intra_socket_16_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_intra_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_intra_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_intra_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

all_rfo_write_inter_socket: all_rfo_write_inter_socket_2_threads all_rfo_write_inter_socket_4_threads all_rfo_write_inter_socket_8_threads all_rfo_write_inter_socket_16_threads

all_all_rfo_write_inter_socket: all_rfo_write_inter_socket_2_threads all_rfo_write_inter_socket_3_threads all_rfo_write_inter_socket_4_threads all_rfo_write_inter_socket_5_threads all_rfo_write_inter_socket_6_threads all_rfo_write_inter_socket_7_threads all_rfo_write_inter_socket_8_threads

all_rfo_write_inter_socket_2_threads: metric_extractor_install volume_install all_rfo_write_inter_socket_run_2_threads all_rfo_write_inter_socket_extract_metrics_2_threads

all_rfo_write_inter_socket_3_threads: metric_extractor_install volume_install all_rfo_write_inter_socket_run_3_threads all_rfo_write_inter_socket_extract_metrics_3_threads

all_rfo_write_inter_socket_4_threads: metric_extractor_install volume_install all_rfo_write_inter_socket_run_4_threads all_rfo_write_inter_socket_extract_metrics_4_threads

all_rfo_write_inter_socket_5_threads: metric_extractor_install volume_install all_rfo_write_inter_socket_run_5_threads all_rfo_write_inter_socket_extract_metrics_5_threads

all_rfo_write_inter_socket_6_threads: metric_extractor_install volume_install all_rfo_write_inter_socket_run_6_threads all_rfo_write_inter_socket_extract_metrics_6_threads

all_rfo_write_inter_socket_7_threads: metric_extractor_install volume_install all_rfo_write_inter_socket_run_7_threads all_rfo_write_inter_socket_extract_metrics_7_threads

all_rfo_write_inter_socket_8_threads: metric_extractor_install volume_install all_rfo_write_inter_socket_run_8_threads all_rfo_write_inter_socket_extract_metrics_8_threads

all_rfo_write_inter_socket_16_threads: metric_extractor_install volume_install all_rfo_write_inter_socket_run_16_threads all_rfo_write_inter_socket_extract_metrics_16_threads

all_rfo_write_inter_socket_run_2_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_write_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 10" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_write -n 2 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_write_inter_socket_extract_metrics_2_threads:
	dump_file="all_rfo_write_inter_socket_2_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

all_rfo_write_inter_socket_run_3_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_write_inter_socket_3_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 1 10" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_write -n 3 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_write_inter_socket_extract_metrics_3_threads:
	dump_file="all_rfo_write_inter_socket_3_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_inter_socket_3_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_inter_socket_3_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_inter_socket_3_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

all_rfo_write_inter_socket_run_4_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_write_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 1 10 11" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_write -n 4 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_write_inter_socket_extract_metrics_4_threads:
	dump_file="all_rfo_write_inter_socket_4_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

all_rfo_write_inter_socket_run_5_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_write_inter_socket_5_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 1 2 10 11" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_write -n 5 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_write_inter_socket_extract_metrics_5_threads:
	dump_file="all_rfo_write_inter_socket_5_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_inter_socket_5_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_inter_socket_5_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_inter_socket_5_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

all_rfo_write_inter_socket_run_6_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_write_inter_socket_6_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 1 2 10 11 12" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_write -n 6 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_write_inter_socket_extract_metrics_6_threads:
	dump_file="all_rfo_write_inter_socket_6_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_inter_socket_6_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_inter_socket_6_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_inter_socket_6_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

all_rfo_write_inter_socket_run_7_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_write_inter_socket_7_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 1 2 3 10 11 12" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_write -n 7 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_write_inter_socket_extract_metrics_7_threads:
	dump_file="all_rfo_write_inter_socket_7_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_inter_socket_7_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_inter_socket_7_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_inter_socket_7_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

all_rfo_write_inter_socket_run_8_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_write_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 1 2 3 10 11 12 13" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_write -n 8 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_write_inter_socket_extract_metrics_8_threads:
	dump_file="all_rfo_write_inter_socket_8_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

all_rfo_write_inter_socket_run_16_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_write_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 1 2 3 4 5 6 7 10 11 12 13 14 15 16 17" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_write -n 16 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_write_inter_socket_extract_metrics_16_threads:
	dump_file="all_rfo_write_inter_socket_16_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_write_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_verification: volume_write_verification volume_add_verification  volume_exchg_verification 

volume_write_verification: volume_write_intra_socket  volume_write_inter_socket 

volume_add_verification: volume_add_intra_socket  volume_add_inter_socket 

volume_exchg_verification: volume_exchg_intra_socket  volume_exchg_inter_socket 

volume_write_intra_socket: volume_write_intra_socket_2_threads volume_write_intra_socket_4_threads volume_write_intra_socket_8_threads

all_volume_write_intra_socket: volume_write_intra_socket_2_threads volume_write_intra_socket_3_threads volume_write_intra_socket_4_threads volume_write_intra_socket_5_threads volume_write_intra_socket_6_threads volume_write_intra_socket_7_threads volume_write_intra_socket_8_threads

volume_write_inter_socket: volume_write_inter_socket_2_threads volume_write_inter_socket_4_threads volume_write_inter_socket_8_threads volume_write_inter_socket_16_threads

all_volume_write_inter_socket: volume_write_inter_socket_2_threads volume_write_inter_socket_3_threads volume_write_inter_socket_4_threads volume_write_inter_socket_5_threads volume_write_inter_socket_6_threads volume_write_inter_socket_7_threads volume_write_inter_socket_8_threads volume_write_inter_socket_16_threads

volume_add_intra_socket: volume_add_intra_socket_2_threads volume_add_intra_socket_4_threads volume_add_intra_socket_8_threads

volume_add_inter_socket: volume_add_inter_socket_2_threads volume_add_inter_socket_4_threads volume_add_inter_socket_8_threads volume_add_inter_socket_16_threads

volume_exchg_intra_socket: volume_exchg_intra_socket_2_threads volume_exchg_intra_socket_4_threads volume_exchg_intra_socket_8_threads

volume_exchg_inter_socket: volume_exchg_inter_socket_2_threads volume_exchg_inter_socket_4_threads volume_exchg_inter_socket_8_threads volume_exchg_inter_socket_16_threads

volume_write_intra_socket_2_threads: metric_extractor_install volume_install volume_write_intra_socket_run_2_threads volume_write_intra_socket_extract_metrics_2_threads

volume_write_intra_socket_3_threads: metric_extractor_install volume_install volume_write_intra_socket_run_3_threads volume_write_intra_socket_extract_metrics_3_threads

volume_write_intra_socket_4_threads: metric_extractor_install volume_install volume_write_intra_socket_run_4_threads volume_write_intra_socket_extract_metrics_4_threads

volume_write_intra_socket_5_threads: metric_extractor_install volume_install volume_write_intra_socket_run_5_threads volume_write_intra_socket_extract_metrics_5_threads

volume_write_intra_socket_6_threads: metric_extractor_install volume_install volume_write_intra_socket_run_6_threads volume_write_intra_socket_extract_metrics_6_threads

volume_write_intra_socket_7_threads: metric_extractor_install volume_install volume_write_intra_socket_run_7_threads volume_write_intra_socket_extract_metrics_7_threads

volume_write_intra_socket_8_threads: metric_extractor_install volume_install volume_write_intra_socket_run_8_threads volume_write_intra_socket_extract_metrics_8_threads

volume_write_intra_socket_16_threads: metric_extractor_install volume_install volume_write_intra_socket_run_16_threads volume_write_intra_socket_extract_metrics_16_threads

volume_write_intra_socket_run_2_threads: write-volume/ubench_write  
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_intra_socket_2_threads_$$i  ./write-volume/ubench_write -n 2 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_intra_socket_2_threads_$$i ./write-volume/ubench_write -n 2 -s $$i -f 0.0 -i 100000000  2>&1 | tee $$dump_file ;  \
	done

volume_write_intra_socket_extract_metrics_2_threads:
	dump_file="volume_write_intra_socket_2_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_2_threads_$$i/ubench_write-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_2_threads_$$i/ubench_write-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_2_threads_$$i/ubench_write-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_2_threads_$$i/ubench_write-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_2_threads_$$i/ubench_write-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_2_threads_$$i/ubench_write-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_write_intra_socket_run_3_threads: write-volume/ubench_write  
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_intra_socket_3_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_intra_socket_3_threads_$$i  ./write-volume/ubench_write -n 3 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_intra_socket_3_threads_$$i ./write-volume/ubench_write -n 3 -s $$i -f 0.0 -i 100000000  2>&1 | tee $$dump_file ;  \
	done

volume_write_intra_socket_extract_metrics_3_threads:
	dump_file="volume_write_intra_socket_3_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_3_threads_$$i/ubench_write-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_3_threads_$$i/ubench_write-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_3_threads_$$i/ubench_write-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_3_threads_$$i/ubench_write-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_3_threads_$$i/ubench_write-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_3_threads_$$i/ubench_write-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_intra_socket_3_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_intra_socket_3_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_write_intra_socket_run_4_threads: write-volume/ubench_write
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		GOMP_CPU_AFFINITY="0 1 2 3" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_intra_socket_4_threads_$$i ./write-volume/ubench_write -n 4 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ;  \
	done

volume_write_intra_socket_extract_metrics_4_threads:
	dump_file="volume_write_intra_socket_4_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_4_threads_$$i/ubench_write-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_4_threads_$$i/ubench_write-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_4_threads_$$i/ubench_write-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_4_threads_$$i/ubench_write-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_4_threads_$$i/ubench_write-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_4_threads_$$i/ubench_write-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_write_intra_socket_run_5_threads: write-volume/ubench_write  
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_intra_socket_5_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3 4\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_intra_socket_5_threads_$$i  ./write-volume/ubench_write -n 5 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3 4" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_intra_socket_5_threads_$$i ./write-volume/ubench_write -n 5 -s $$i -f 0.0 -i 100000000  2>&1 | tee $$dump_file ;  \
	done

volume_write_intra_socket_extract_metrics_5_threads:
	dump_file="volume_write_intra_socket_5_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_5_threads_$$i/ubench_write-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_5_threads_$$i/ubench_write-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_5_threads_$$i/ubench_write-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_5_threads_$$i/ubench_write-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_5_threads_$$i/ubench_write-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_5_threads_$$i/ubench_write-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_intra_socket_5_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_intra_socket_5_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_write_intra_socket_run_6_threads: write-volume/ubench_write  
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_intra_socket_6_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3 4 5\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_intra_socket_6_threads_$$i  ./write-volume/ubench_write -n 6 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3 4 5" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_intra_socket_6_threads_$$i ./write-volume/ubench_write -n 6 -s $$i -f 0.0 -i 100000000  2>&1 | tee $$dump_file ;  \
	done

volume_write_intra_socket_extract_metrics_6_threads:
	dump_file="volume_write_intra_socket_6_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_6_threads_$$i/ubench_write-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_6_threads_$$i/ubench_write-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_6_threads_$$i/ubench_write-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_6_threads_$$i/ubench_write-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_6_threads_$$i/ubench_write-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_6_threads_$$i/ubench_write-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_intra_socket_6_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_intra_socket_6_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_write_intra_socket_run_7_threads: write-volume/ubench_write  
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_intra_socket_7_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3 4 5 6\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_intra_socket_7_threads_$$i  ./write-volume/ubench_write -n 7 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3 4 5 6" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_intra_socket_7_threads_$$i ./write-volume/ubench_write -n 7 -s $$i -f 0.0 -i 100000000  2>&1 | tee $$dump_file ;  \
	done

volume_write_intra_socket_extract_metrics_7_threads:
	dump_file="volume_write_intra_socket_7_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_7_threads_$$i/ubench_write-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_7_threads_$$i/ubench_write-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_7_threads_$$i/ubench_write-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_7_threads_$$i/ubench_write-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_7_threads_$$i/ubench_write-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_7_threads_$$i/ubench_write-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_intra_socket_7_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_intra_socket_7_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_write_intra_socket_run_8_threads: write-volume/ubench_write
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3 4 5 6 7\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_intra_socket_8_threads_$$i  ./write-volume/ubench_write -n 8 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3 4 5 6 7" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_intra_socket_8_threads_$$i ./write-volume/ubench_write -n 8 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ;  \
	done

volume_write_intra_socket_extract_metrics_8_threads:
	dump_file="volume_write_intra_socket_8_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_8_threads_$$i/ubench_write-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_8_threads_$$i/ubench_write-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_8_threads_$$i/ubench_write-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_8_threads_$$i/ubench_write-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_8_threads_$$i/ubench_write-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_8_threads_$$i/ubench_write-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_write_intra_socket_run_16_threads: write-volume/ubench_write
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_intra_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3 4 5 6 7 8 9 20 21 22 23 24 25\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_intra_socket_16_threads_$$i  ./write-volume/ubench_write -n 16 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3 4 5 6 7 8 9 20 21 22 23 24 25" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_intra_socket_16_threads_$$i ./write-volume/ubench_write -n 16 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ;  \
	done

volume_write_intra_socket_extract_metrics_16_threads:
	dump_file="volume_write_intra_socket_16_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_16_threads_$$i/ubench_write-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_16_threads_$$i/ubench_write-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_16_threads_$$i/ubench_write-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_16_threads_$$i/ubench_write-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_16_threads_$$i/ubench_write-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_intra_socket_16_threads_$$i/ubench_write-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_intra_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_intra_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_write_inter_socket_2_threads: metric_extractor_install volume_install volume_write_inter_socket_run_2_threads volume_write_inter_socket_extract_metrics_2_threads

volume_write_inter_socket_extract_metrics_2_threads:
	dump_file="volume_write_inter_socket_2_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_2_threads_$$i/ubench_write-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_2_threads_$$i/ubench_write-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_2_threads_$$i/ubench_write-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_2_threads_$$i/ubench_write-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_2_threads_$$i/ubench_write-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_2_threads_$$i/ubench_write-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;


volume_write_inter_socket_3_threads: metric_extractor_install volume_install volume_write_inter_socket_run_3_threads volume_write_inter_socket_extract_metrics_3_threads

volume_write_inter_socket_extract_metrics_3_threads:
	dump_file="volume_write_inter_socket_3_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_3_threads_$$i/ubench_write-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_3_threads_$$i/ubench_write-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_3_threads_$$i/ubench_write-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_3_threads_$$i/ubench_write-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_3_threads_$$i/ubench_write-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_3_threads_$$i/ubench_write-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_inter_socket_3_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_inter_socket_3_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_write_inter_socket_4_threads: metric_extractor_install volume_install volume_write_inter_socket_run_4_threads volume_write_inter_socket_extract_metrics_4_threads

volume_write_inter_socket_extract_metrics_4_threads:
	dump_file="volume_write_inter_socket_4_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_4_threads_$$i/ubench_write-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_4_threads_$$i/ubench_write-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_4_threads_$$i/ubench_write-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_4_threads_$$i/ubench_write-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_4_threads_$$i/ubench_write-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_4_threads_$$i/ubench_write-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_write_inter_socket_5_threads: metric_extractor_install volume_install volume_write_inter_socket_run_5_threads volume_write_inter_socket_extract_metrics_5_threads

volume_write_inter_socket_extract_metrics_5_threads:
	dump_file="volume_write_inter_socket_5_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_5_threads_$$i/ubench_write-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_5_threads_$$i/ubench_write-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_5_threads_$$i/ubench_write-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_5_threads_$$i/ubench_write-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_5_threads_$$i/ubench_write-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_5_threads_$$i/ubench_write-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_inter_socket_5_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_inter_socket_5_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_write_inter_socket_6_threads: metric_extractor_install volume_install volume_write_inter_socket_run_6_threads volume_write_inter_socket_extract_metrics_6_threads

volume_write_inter_socket_extract_metrics_6_threads:
	dump_file="volume_write_inter_socket_6_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_6_threads_$$i/ubench_write-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_6_threads_$$i/ubench_write-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_6_threads_$$i/ubench_write-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_6_threads_$$i/ubench_write-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_6_threads_$$i/ubench_write-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_6_threads_$$i/ubench_write-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_inter_socket_6_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_inter_socket_6_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_write_inter_socket_7_threads: metric_extractor_install volume_install volume_write_inter_socket_run_7_threads volume_write_inter_socket_extract_metrics_7_threads

volume_write_inter_socket_extract_metrics_7_threads:
	dump_file="volume_write_inter_socket_7_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_7_threads_$$i/ubench_write-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_7_threads_$$i/ubench_write-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_7_threads_$$i/ubench_write-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_7_threads_$$i/ubench_write-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_7_threads_$$i/ubench_write-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_7_threads_$$i/ubench_write-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_inter_socket_7_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_inter_socket_7_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_write_inter_socket_8_threads: metric_extractor_install volume_install volume_write_inter_socket_run_8_threads volume_write_inter_socket_extract_metrics_8_threads

volume_write_inter_socket_extract_metrics_8_threads:
	dump_file="volume_write_inter_socket_8_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_8_threads_$$i/ubench_write-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_8_threads_$$i/ubench_write-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_8_threads_$$i/ubench_write-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_8_threads_$$i/ubench_write-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_8_threads_$$i/ubench_write-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_8_threads_$$i/ubench_write-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_write_inter_socket_16_threads: metric_extractor_install volume_install volume_write_inter_socket_run_16_threads volume_write_inter_socket_extract_metrics_16_threads

volume_write_inter_socket_extract_metrics_16_threads:
	dump_file="volume_write_inter_socket_16_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_16_threads_$$i/ubench_write-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_16_threads_$$i/ubench_write-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_16_threads_$$i/ubench_write-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_16_threads_$$i/ubench_write-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_16_threads_$$i/ubench_write-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_write_inter_socket_16_threads_$$i/ubench_write-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_write_inter_socket_run_2_threads: write-volume/ubench_write
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 10\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_inter_socket_2_threads_$$i  ./write-volume/ubench_write -n 2 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 10" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_inter_socket_2_threads_$$i ./write-volume/ubench_write -n 2 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ;  \
	done

volume_write_inter_socket_run_3_threads: write-volume/ubench_write
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_inter_socket_3_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 10\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_inter_socket_3_threads_$$i  ./write-volume/ubench_write -n 3 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 10" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_inter_socket_3_threads_$$i ./write-volume/ubench_write -n 3 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ;  \
	done

volume_write_inter_socket_run_4_threads: write-volume/ubench_write
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 10 11\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_inter_socket_4_threads_$$i  ./write-volume/ubench_write -n 4 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 10 11" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_inter_socket_4_threads_$$i ./write-volume/ubench_write -n 4 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ;  \
	done

volume_write_inter_socket_run_5_threads: write-volume/ubench_write
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_inter_socket_5_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 10 11\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_inter_socket_5_threads_$$i  ./write-volume/ubench_write -n 5 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 10 11" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_inter_socket_5_threads_$$i ./write-volume/ubench_write -n 5 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ;  \
	done

volume_write_inter_socket_run_6_threads: write-volume/ubench_write
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_inter_socket_6_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 10 11 12\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_inter_socket_6_threads_$$i  ./write-volume/ubench_write -n 6 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 10 11 12" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_inter_socket_6_threads_$$i ./write-volume/ubench_write -n 6 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ;  \
	done

volume_write_inter_socket_run_7_threads: write-volume/ubench_write
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_inter_socket_7_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3 10 11 12\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_inter_socket_7_threads_$$i  ./write-volume/ubench_write -n 7 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3 10 11 12" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_inter_socket_7_threads_$$i ./write-volume/ubench_write -n 7 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ;  \
	done

volume_write_inter_socket_run_8_threads: write-volume/ubench_write
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3 10 11 12 13\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_inter_socket_8_threads_$$i  ./write-volume/ubench_write -n 8 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3 10 11 12 13" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_inter_socket_8_threads_$$i ./write-volume/ubench_write -n 8 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ;  \
	done

volume_write_inter_socket_run_16_threads: write-volume/ubench_write
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_write_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3 4 5 6 7 10 11 12 13 14 15 16 17\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_inter_socket_16_threads_$$i  ./write-volume/ubench_write -n 16 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3 4 5 6 7 10 11 12 13 14 15 16 17" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_write_inter_socket_16_threads_$$i ./write-volume/ubench_write -n 16 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ;  \
	done

all_rfo_add: all_rfo_add_intra_socket all_rfo_add_inter_socket

all_rfo_add_intra_socket: all_rfo_add_intra_socket_2_threads all_rfo_add_intra_socket_4_threads all_rfo_add_intra_socket_8_threads

all_rfo_add_intra_socket_2_threads: metric_extractor_install volume_install all_rfo_add_intra_socket_run_2_threads all_rfo_add_intra_socket_extract_metrics_2_threads

all_rfo_add_intra_socket_4_threads: metric_extractor_install volume_install all_rfo_add_intra_socket_run_4_threads all_rfo_add_intra_socket_extract_metrics_4_threads

all_rfo_add_intra_socket_8_threads: metric_extractor_install volume_install all_rfo_add_intra_socket_run_8_threads all_rfo_add_intra_socket_extract_metrics_8_threads

all_rfo_add_intra_socket_run_2_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_add_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 1" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_add -n 2 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_add_intra_socket_extract_metrics_2_threads:
	dump_file="all_rfo_add_intra_socket_2_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_add_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_add_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_add_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

all_rfo_add_intra_socket_run_4_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_add_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 1 2 3" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_add -n 4 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_add_intra_socket_extract_metrics_4_threads:
	dump_file="all_rfo_add_intra_socket_4_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_add_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_add_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_add_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

all_rfo_add_intra_socket_run_8_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_add_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 1 2 3 4 5 6 7" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_add -n 8 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_add_intra_socket_extract_metrics_8_threads:
	dump_file="all_rfo_add_intra_socket_8_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_add_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_add_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_add_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

all_rfo_add_inter_socket: all_rfo_add_inter_socket_2_threads all_rfo_add_inter_socket_4_threads all_rfo_add_inter_socket_8_threads all_rfo_add_inter_socket_16_threads

all_rfo_add_inter_socket_2_threads: metric_extractor_install volume_install all_rfo_add_inter_socket_run_2_threads all_rfo_add_inter_socket_extract_metrics_2_threads

all_rfo_add_inter_socket_4_threads: metric_extractor_install volume_install all_rfo_add_inter_socket_run_4_threads all_rfo_add_inter_socket_extract_metrics_4_threads

all_rfo_add_inter_socket_8_threads: metric_extractor_install volume_install all_rfo_add_inter_socket_run_8_threads all_rfo_add_inter_socket_extract_metrics_8_threads

all_rfo_add_inter_socket_16_threads: metric_extractor_install volume_install all_rfo_add_inter_socket_run_16_threads all_rfo_add_inter_socket_extract_metrics_16_threads

all_rfo_add_inter_socket_run_2_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_add_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 10" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_add -n 2 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_add_inter_socket_extract_metrics_2_threads:
	dump_file="all_rfo_add_inter_socket_2_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_add_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_add_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_add_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

all_rfo_add_inter_socket_run_4_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_add_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 1 10 11" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_add -n 4 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_add_inter_socket_extract_metrics_4_threads:
	dump_file="all_rfo_add_inter_socket_4_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_add_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_add_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_add_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

all_rfo_add_inter_socket_run_8_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_add_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 1 2 3 10 11 12 13" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_add -n 8 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_add_inter_socket_extract_metrics_8_threads:
	dump_file="all_rfo_add_inter_socket_8_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_add_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_add_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_add_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

all_rfo_add_inter_socket_run_16_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_add_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 1 2 3 4 5 6 7 10 11 12 13 14 15 16 17" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_add -n 16 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_add_inter_socket_extract_metrics_16_threads:
	dump_file="all_rfo_add_inter_socket_16_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_add_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_add_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_add_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_add_intra_socket_2_threads: metric_extractor_install volume_install volume_add_intra_socket_run_2_threads volume_add_intra_socket_extract_metrics_2_threads

volume_add_intra_socket_extract_metrics_2_threads:
	dump_file="volume_add_intra_socket_2_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_intra_socket_2_threads_$$i/ubench_add-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_intra_socket_2_threads_$$i/ubench_add-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_intra_socket_2_threads_$$i/ubench_add-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_intra_socket_2_threads_$$i/ubench_add-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_intra_socket_2_threads_$$i/ubench_add-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_intra_socket_2_threads_$$i/ubench_add-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_add_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_add_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_add_intra_socket_4_threads: metric_extractor_install volume_install volume_add_intra_socket_run_4_threads volume_add_intra_socket_extract_metrics_4_threads

volume_add_intra_socket_extract_metrics_4_threads:
	dump_file="volume_add_intra_socket_4_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_intra_socket_4_threads_$$i/ubench_add-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_intra_socket_4_threads_$$i/ubench_add-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_intra_socket_4_threads_$$i/ubench_add-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_intra_socket_4_threads_$$i/ubench_add-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_intra_socket_4_threads_$$i/ubench_add-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_intra_socket_4_threads_$$i/ubench_add-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_add_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_add_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_add_intra_socket_8_threads: metric_extractor_install volume_install volume_add_intra_socket_run_8_threads volume_add_intra_socket_extract_metrics_8_threads

volume_add_intra_socket_extract_metrics_8_threads:
	dump_file="volume_add_intra_socket_8_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_intra_socket_8_threads_$$i/ubench_add-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_intra_socket_8_threads_$$i/ubench_add-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_intra_socket_8_threads_$$i/ubench_add-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_intra_socket_8_threads_$$i/ubench_add-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_intra_socket_8_threads_$$i/ubench_add-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_intra_socket_8_threads_$$i/ubench_add-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_add_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_add_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_add_intra_socket_run_2_threads: write-volume/ubench_add
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_add_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_add_intra_socket_2_threads_$$i  ./write-volume/ubench_add -n 2 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_add_intra_socket_2_threads_$$i ./write-volume/ubench_add -n 2 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ;  \
	done

volume_add_intra_socket_run_4_threads: write-volume/ubench_add
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_add_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_add_intra_socket_4_threads_$$i  ./write-volume/ubench_add -n 4 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_add_intra_socket_4_threads_$$i ./write-volume/ubench_add -n 4 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ;  \
	done

volume_add_intra_socket_run_8_threads: write-volume/ubench_add
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_add_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3 4 5 6 7\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_add_intra_socket_8_threads_$$i  ./write-volume/ubench_add -n 8 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3 4 5 6 7" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_add_intra_socket_8_threads_$$i ./write-volume/ubench_add -n 8 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ;  \
	done

volume_add_inter_socket_2_threads: metric_extractor_install volume_install volume_add_inter_socket_run_2_threads volume_add_inter_socket_extract_metrics_2_threads

volume_add_inter_socket_extract_metrics_2_threads:
	dump_file="volume_add_inter_socket_2_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_inter_socket_2_threads_$$i/ubench_add-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_inter_socket_2_threads_$$i/ubench_add-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_inter_socket_2_threads_$$i/ubench_add-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_inter_socket_2_threads_$$i/ubench_add-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_inter_socket_2_threads_$$i/ubench_add-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_inter_socket_2_threads_$$i/ubench_add-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_add_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_add_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_add_inter_socket_4_threads: metric_extractor_install volume_install volume_add_inter_socket_run_4_threads volume_add_inter_socket_extract_metrics_4_threads

volume_add_inter_socket_extract_metrics_4_threads:
	dump_file="volume_add_inter_socket_4_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_inter_socket_4_threads_$$i/ubench_add-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_inter_socket_4_threads_$$i/ubench_add-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_inter_socket_4_threads_$$i/ubench_add-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_inter_socket_4_threads_$$i/ubench_add-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_inter_socket_4_threads_$$i/ubench_add-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_inter_socket_4_threads_$$i/ubench_add-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_add_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_add_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_add_inter_socket_8_threads: metric_extractor_install volume_install volume_add_inter_socket_run_8_threads volume_add_inter_socket_extract_metrics_8_threads

volume_add_inter_socket_extract_metrics_8_threads:
	dump_file="volume_add_inter_socket_8_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_inter_socket_8_threads_$$i/ubench_add-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_inter_socket_8_threads_$$i/ubench_add-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_inter_socket_8_threads_$$i/ubench_add-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_inter_socket_8_threads_$$i/ubench_add-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_inter_socket_8_threads_$$i/ubench_add-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_inter_socket_8_threads_$$i/ubench_add-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_add_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_add_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_add_inter_socket_16_threads: metric_extractor_install volume_install volume_add_inter_socket_run_16_threads volume_add_inter_socket_extract_metrics_16_threads

volume_add_inter_socket_extract_metrics_16_threads:
	dump_file="volume_add_inter_socket_16_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_inter_socket_16_threads_$$i/ubench_add-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_inter_socket_16_threads_$$i/ubench_add-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_inter_socket_16_threads_$$i/ubench_add-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_inter_socket_16_threads_$$i/ubench_add-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_inter_socket_16_threads_$$i/ubench_add-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_add_inter_socket_16_threads_$$i/ubench_add-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_add_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_add_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_add_inter_socket_run_2_threads: write-volume/ubench_add
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_add_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 10\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_add_inter_socket_2_threads_$$i  ./write-volume/ubench_add -n 2 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 10" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_add_inter_socket_2_threads_$$i ./write-volume/ubench_add -n 2 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ;  \
	done

volume_add_inter_socket_run_4_threads: write-volume/ubench_add
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_add_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 10 11\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_add_inter_socket_4_threads_$$i  ./write-volume/ubench_add -n 4 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 10 11" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_add_inter_socket_4_threads_$$i ./write-volume/ubench_add -n 4 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ;  \
	done

volume_add_inter_socket_run_8_threads: write-volume/ubench_add
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_add_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3 10 11 12 13\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_add_inter_socket_8_threads_$$i  ./write-volume/ubench_add -n 8 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3 10 11 12 13" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_add_inter_socket_8_threads_$$i ./write-volume/ubench_add -n 8 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ;  \
        done

volume_add_inter_socket_run_16_threads: write-volume/ubench_add
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_add_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3 4 5 6 7 10 11 12 13 14 15 16 17\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_add_inter_socket_16_threads_$$i  ./write-volume/ubench_add -n 16 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3 4 5 6 7 10 11 12 13 14 15 16 17" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_add_inter_socket_16_threads_$$i ./write-volume/ubench_add -n 16 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ;  \
        done

all_rfo_exchg: all_rfo_exchg_intra_socket all_rfo_exchg_inter_socket

all_rfo_exchg_intra_socket: all_rfo_exchg_intra_socket_2_threads all_rfo_exchg_intra_socket_4_threads all_rfo_exchg_intra_socket_8_threads

all_rfo_exchg_intra_socket_2_threads: metric_extractor_install volume_install all_rfo_exchg_intra_socket_run_2_threads all_rfo_exchg_intra_socket_extract_metrics_2_threads

all_rfo_exchg_intra_socket_4_threads: metric_extractor_install volume_install all_rfo_exchg_intra_socket_run_4_threads all_rfo_exchg_intra_socket_extract_metrics_4_threads

all_rfo_exchg_intra_socket_8_threads: metric_extractor_install volume_install all_rfo_exchg_intra_socket_run_8_threads all_rfo_exchg_intra_socket_extract_metrics_8_threads

all_rfo_exchg_intra_socket_run_2_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_exchg_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 1" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_exchg -n 2 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_exchg_intra_socket_extract_metrics_2_threads:
	dump_file="all_rfo_exchg_intra_socket_2_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_exchg_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_exchg_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_exchg_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

all_rfo_exchg_intra_socket_run_4_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_exchg_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 1 2 3" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_exchg -n 4 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_exchg_intra_socket_extract_metrics_4_threads:
	dump_file="all_rfo_exchg_intra_socket_4_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_exchg_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_exchg_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_exchg_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

all_rfo_exchg_intra_socket_run_8_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_exchg_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 1 2 3 4 5 6 7" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_exchg -n 8 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_exchg_intra_socket_extract_metrics_8_threads:
	dump_file="all_rfo_exchg_intra_socket_8_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_exchg_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_exchg_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_exchg_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

all_rfo_exchg_inter_socket: all_rfo_exchg_inter_socket_2_threads all_rfo_exchg_inter_socket_4_threads all_rfo_exchg_inter_socket_8_threads all_rfo_exchg_inter_socket_16_threads

all_rfo_exchg_inter_socket_2_threads: metric_extractor_install volume_install all_rfo_exchg_inter_socket_run_2_threads all_rfo_exchg_inter_socket_extract_metrics_2_threads

all_rfo_exchg_inter_socket_4_threads: metric_extractor_install volume_install all_rfo_exchg_inter_socket_run_4_threads all_rfo_exchg_inter_socket_extract_metrics_4_threads

all_rfo_exchg_inter_socket_8_threads: metric_extractor_install volume_install all_rfo_exchg_inter_socket_run_8_threads all_rfo_exchg_inter_socket_extract_metrics_8_threads

all_rfo_exchg_inter_socket_16_threads: metric_extractor_install volume_install all_rfo_exchg_inter_socket_run_16_threads all_rfo_exchg_inter_socket_extract_metrics_16_threads

all_rfo_exchg_inter_socket_run_2_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_exchg_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 10" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_exchg -n 2 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_exchg_inter_socket_extract_metrics_2_threads:
	dump_file="all_rfo_exchg_inter_socket_2_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_exchg_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_exchg_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_exchg_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

all_rfo_exchg_inter_socket_run_4_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_exchg_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 1 10 11" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_exchg -n 4 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_exchg_inter_socket_extract_metrics_4_threads:
	dump_file="all_rfo_exchg_inter_socket_4_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_exchg_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_exchg_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_exchg_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

all_rfo_exchg_inter_socket_run_8_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_exchg_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 1 2 3 10 11 12 13" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_exchg -n 8 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_exchg_inter_socket_extract_metrics_8_threads:
	dump_file="all_rfo_exchg_inter_socket_8_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_exchg_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_exchg_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_exchg_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

all_rfo_exchg_inter_socket_run_16_threads:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 ; do \
		string1="all_rfo_exchg_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "----------------" ; \
		GOMP_CPU_AFFINITY="0 1 2 3 4 5 6 7 10 11 12 13 14 15 16 17" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${perf_bin}/perf stat -e re224 ./write-volume/ubench_exchg -n 16 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ; \
	done

all_rfo_exchg_inter_socket_extract_metrics_16_threads:
	dump_file="all_rfo_exchg_inter_socket_16_threads_metrics.txt" ; \
	echo "all RFO counts" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_exchg_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_communication_count $$input_file 6 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_exchg_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="all_rfo_exchg_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_exchg_intra_socket_2_threads: metric_extractor_install volume_install volume_exchg_intra_socket_run_2_threads volume_exchg_intra_socket_extract_metrics_2_threads


volume_exchg_intra_socket_extract_metrics_2_threads:
	dump_file="volume_exchg_intra_socket_2_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_intra_socket_2_threads_$$i/ubench_exchg-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_intra_socket_2_threads_$$i/ubench_exchg-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_intra_socket_2_threads_$$i/ubench_exchg-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_intra_socket_2_threads_$$i/ubench_exchg-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_intra_socket_2_threads_$$i/ubench_exchg-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_intra_socket_2_threads_$$i/ubench_exchg-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_exchg_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_exchg_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_exchg_intra_socket_4_threads: metric_extractor_install volume_install volume_exchg_intra_socket_run_4_threads volume_exchg_intra_socket_extract_metrics_4_threads

volume_exchg_intra_socket_extract_metrics_4_threads:
	dump_file="volume_exchg_intra_socket_4_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_intra_socket_4_threads_$$i/ubench_exchg-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_intra_socket_4_threads_$$i/ubench_exchg-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_intra_socket_4_threads_$$i/ubench_exchg-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_intra_socket_4_threads_$$i/ubench_exchg-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_intra_socket_4_threads_$$i/ubench_exchg-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_intra_socket_4_threads_$$i/ubench_exchg-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_exchg_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_exchg_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_exchg_intra_socket_8_threads: metric_extractor_install volume_install volume_exchg_intra_socket_run_8_threads volume_exchg_intra_socket_extract_metrics_8_threads

volume_exchg_intra_socket_extract_metrics_8_threads:
	dump_file="volume_exchg_intra_socket_8_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_intra_socket_8_threads_$$i/ubench_exchg-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_intra_socket_8_threads_$$i/ubench_exchg-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_intra_socket_8_threads_$$i/ubench_exchg-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_intra_socket_8_threads_$$i/ubench_exchg-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_intra_socket_8_threads_$$i/ubench_exchg-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_intra_socket_8_threads_$$i/ubench_exchg-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_exchg_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_exchg_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_exchg_intra_socket_run_2_threads: write-volume/ubench_exchg
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_exchg_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_exchg_intra_socket_2_threads_$$i  ./write-volume/ubench_exchg -n 2 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_exchg_intra_socket_2_threads_$$i ./write-volume/ubench_exchg -n 2 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ;  \
	done

volume_exchg_intra_socket_run_4_threads: write-volume/ubench_exchg
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_exchg_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_exchg_intra_socket_4_threads_$$i  ./write-volume/ubench_exchg -n 4 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_exchg_intra_socket_4_threads_$$i ./write-volume/ubench_exchg -n 4 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ;  \
	done

volume_exchg_intra_socket_run_8_threads: write-volume/ubench_exchg
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_exchg_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3 4 5 6 7\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_exchg_intra_socket_8_threads_$$i  ./write-volume/ubench_exchg -n 8 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3 4 5 6 7" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_exchg_intra_socket_8_threads_$$i ./write-volume/ubench_exchg -n 8 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ;  \
	done

volume_exchg_inter_socket_2_threads: metric_extractor_install volume_install volume_exchg_inter_socket_run_2_threads volume_exchg_inter_socket_extract_metrics_2_threads

volume_exchg_inter_socket_extract_metrics_2_threads:
	dump_file="volume_exchg_inter_socket_2_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_inter_socket_2_threads_$$i/ubench_exchg-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_inter_socket_2_threads_$$i/ubench_exchg-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_inter_socket_2_threads_$$i/ubench_exchg-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_inter_socket_2_threads_$$i/ubench_exchg-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_inter_socket_2_threads_$$i/ubench_exchg-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_inter_socket_2_threads_$$i/ubench_exchg-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_exchg_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_exchg_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_exchg_inter_socket_4_threads: metric_extractor_install volume_install volume_exchg_inter_socket_run_4_threads volume_exchg_inter_socket_extract_metrics_4_threads

volume_exchg_inter_socket_extract_metrics_4_threads:
	dump_file="volume_exchg_inter_socket_4_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_inter_socket_4_threads_$$i/ubench_exchg-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_inter_socket_4_threads_$$i/ubench_exchg-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_inter_socket_4_threads_$$i/ubench_exchg-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_inter_socket_4_threads_$$i/ubench_exchg-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_inter_socket_4_threads_$$i/ubench_exchg-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_inter_socket_4_threads_$$i/ubench_exchg-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_exchg_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_exchg_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_exchg_inter_socket_8_threads: metric_extractor_install volume_install volume_exchg_inter_socket_run_8_threads volume_exchg_inter_socket_extract_metrics_8_threads

volume_exchg_inter_socket_extract_metrics_8_threads:
	dump_file="volume_exchg_inter_socket_8_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_inter_socket_8_threads_$$i/ubench_exchg-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_inter_socket_8_threads_$$i/ubench_exchg-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_inter_socket_8_threads_$$i/ubench_exchg-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_inter_socket_8_threads_$$i/ubench_exchg-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_inter_socket_8_threads_$$i/ubench_exchg-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_inter_socket_8_threads_$$i/ubench_exchg-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_exchg_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_exchg_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_exchg_inter_socket_16_threads: metric_extractor_install volume_install volume_exchg_inter_socket_run_16_threads volume_exchg_inter_socket_extract_metrics_16_threads

volume_exchg_inter_socket_extract_metrics_16_threads:
	dump_file="volume_exchg_inter_socket_16_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_inter_socket_16_threads_$$i/ubench_exchg-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_inter_socket_16_threads_$$i/ubench_exchg-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_inter_socket_16_threads_$$i/ubench_exchg-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_inter_socket_16_threads_$$i/ubench_exchg-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_inter_socket_16_threads_$$i/ubench_exchg-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count volume_exchg_inter_socket_16_threads_$$i/ubench_exchg-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_exchg_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_exchg_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

volume_exchg_inter_socket_run_2_threads: write-volume/ubench_exchg
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_exchg_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 10\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_exchg_inter_socket_2_threads_$$i  ./write-volume/ubench_exchg -n 2 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 10" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_exchg_inter_socket_2_threads_$$i ./write-volume/ubench_exchg -n 2 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ;  \
	done

volume_exchg_inter_socket_run_4_threads: write-volume/ubench_exchg
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_exchg_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 10 11\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_exchg_inter_socket_4_threads_$$i  ./write-volume/ubench_exchg -n 4 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 10 11" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_exchg_inter_socket_4_threads_$$i ./write-volume/ubench_exchg -n 4 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ;  \
	done

volume_exchg_inter_socket_run_8_threads: write-volume/ubench_exchg
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_exchg_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3 10 11 12 13\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_exchg_inter_socket_8_threads_$$i  ./write-volume/ubench_exchg -n 8 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3 10 11 12 13" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_exchg_inter_socket_8_threads_$$i ./write-volume/ubench_exchg -n 8 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ;  \
	done

volume_exchg_inter_socket_run_16_threads: write-volume/ubench_exchg
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="volume_exchg_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3 4 5 6 7 10 11 12 13 14 15 16 17\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o volume_exchg_inter_socket_16_threads_$$i  ./write-volume/ubench_exchg -n 16 -s $$i -f 0.0 -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3 4 5 6 7 10 11 12 13 14 15 16 17" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o volume_exchg_inter_socket_16_threads_$$i ./write-volume/ubench_exchg -n 16 -s $$i -f 0.0 -i 100000000 2>&1 | tee $$dump_file ;  \
	done

false_sharing_verification: false_sharing_write_verification false_sharing_add_verification  false_sharing_exchg_verification

false_sharing_write_verification: false_sharing_write_intra_socket  false_sharing_write_inter_socket

false_sharing_add_verification: false_sharing_add_intra_socket  false_sharing_add_inter_socket

false_sharing_exchg_verification: false_sharing_exchg_intra_socket  false_sharing_exchg_inter_socket

false_sharing_write_intra_socket: false_sharing_write_intra_socket_2_threads false_sharing_write_intra_socket_4_threads false_sharing_write_intra_socket_8_threads

false_sharing_write_intra_socket_2_threads: metric_extractor_install volume_install false_sharing_write_intra_socket_run_2_threads false_sharing_write_intra_socket_extract_metrics_2_threads

false_sharing_write_intra_socket_extract_metrics_2_threads:
	dump_file="false_sharing_write_intra_socket_2_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_intra_socket_2_threads_$$i/ubench_write-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_intra_socket_2_threads_$$i/ubench_write-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_intra_socket_2_threads_$$i/ubench_write-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_intra_socket_2_threads_$$i/ubench_write-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_intra_socket_2_threads_$$i/ubench_write-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_intra_socket_2_threads_$$i/ubench_write-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_write_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_write_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

false_sharing_write_intra_socket_run_2_threads: 
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_write_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_write_intra_socket_2_threads_$$i  ./write-volume/ubench_write -n 2 -s 1.0 -f $$i -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_write_intra_socket_2_threads_$$i ./write-volume/ubench_write -n 2 -s 1.0 -f $$i -i 100000000 2>&1 | tee $$dump_file ;  \
        done

false_sharing_write_intra_socket_4_threads: metric_extractor_install volume_install false_sharing_write_intra_socket_run_4_threads false_sharing_write_intra_socket_extract_metrics_4_threads

false_sharing_write_intra_socket_extract_metrics_4_threads:
	dump_file="false_sharing_write_intra_socket_4_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_intra_socket_4_threads_$$i/ubench_write-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_intra_socket_4_threads_$$i/ubench_write-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_intra_socket_4_threads_$$i/ubench_write-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_intra_socket_4_threads_$$i/ubench_write-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_intra_socket_4_threads_$$i/ubench_write-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_intra_socket_4_threads_$$i/ubench_write-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_write_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_write_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

false_sharing_write_intra_socket_run_4_threads: 
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_write_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_write_intra_socket_4_threads_$$i  ./write-volume/ubench_write -n 4 -s 1.0 -f $$i -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_write_intra_socket_4_threads_$$i ./write-volume/ubench_write -n 4 -s 1.0 -f $$i -i 100000000 2>&1 | tee $$dump_file ;  \
        done

false_sharing_write_intra_socket_8_threads: metric_extractor_install volume_install false_sharing_write_intra_socket_run_8_threads false_sharing_write_intra_socket_extract_metrics_8_threads

false_sharing_write_intra_socket_extract_metrics_8_threads:
	dump_file="false_sharing_write_intra_socket_8_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_intra_socket_8_threads_$$i/ubench_write-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_intra_socket_8_threads_$$i/ubench_write-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_intra_socket_8_threads_$$i/ubench_write-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_intra_socket_8_threads_$$i/ubench_write-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_intra_socket_8_threads_$$i/ubench_write-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_intra_socket_8_threads_$$i/ubench_write-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_write_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_write_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

false_sharing_write_intra_socket_run_8_threads: 
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_write_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3 4 5 6 7\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_write_intra_socket_8_threads_$$i  ./write-volume/ubench_write -n 8 -s 1.0 -f $$i -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3 4 5 6 7" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_write_intra_socket_8_threads_$$i ./write-volume/ubench_write -n 8 -s 1.0 -f $$i -i 100000000 2>&1 | tee $$dump_file ;  \
        done

false_sharing_write_inter_socket: false_sharing_write_inter_socket_2_threads false_sharing_write_inter_socket_4_threads false_sharing_write_inter_socket_8_threads false_sharing_write_inter_socket_16_threads

false_sharing_write_inter_socket_2_threads: metric_extractor_install volume_install false_sharing_write_inter_socket_run_2_threads false_sharing_write_inter_socket_extract_metrics_2_threads

false_sharing_write_inter_socket_extract_metrics_2_threads:
	dump_file="false_sharing_write_inter_socket_2_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_inter_socket_2_threads_$$i/ubench_write-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_inter_socket_2_threads_$$i/ubench_write-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_inter_socket_2_threads_$$i/ubench_write-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_inter_socket_2_threads_$$i/ubench_write-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_inter_socket_2_threads_$$i/ubench_write-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_inter_socket_2_threads_$$i/ubench_write-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_write_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_write_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

false_sharing_write_inter_socket_run_2_threads: 
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_write_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 10\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_write_inter_socket_2_threads_$$i  ./write-volume/ubench_write -n 2 -s 1.0 -f $$i -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 10" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_write_inter_socket_2_threads_$$i ./write-volume/ubench_write -n 2 -s 1.0 -f $$i -i 100000000 2>&1 | tee $$dump_file ;  \
        done

false_sharing_write_inter_socket_4_threads: metric_extractor_install volume_install false_sharing_write_inter_socket_run_4_threads false_sharing_write_inter_socket_extract_metrics_4_threads

false_sharing_write_inter_socket_extract_metrics_4_threads:
	dump_file="false_sharing_write_inter_socket_4_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_inter_socket_4_threads_$$i/ubench_write-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_inter_socket_4_threads_$$i/ubench_write-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_inter_socket_4_threads_$$i/ubench_write-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_inter_socket_4_threads_$$i/ubench_write-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_inter_socket_4_threads_$$i/ubench_write-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_inter_socket_4_threads_$$i/ubench_write-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_write_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_write_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

false_sharing_write_inter_socket_run_4_threads: 
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_write_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 10 11\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_write_inter_socket_4_threads_$$i  ./write-volume/ubench_write -n 4 -s 1.0 -f $$i -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 10 11" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_write_inter_socket_4_threads_$$i ./write-volume/ubench_write -n 4 -s 1.0 -f $$i -i 100000000 2>&1 | tee $$dump_file ;  \
	done

false_sharing_write_inter_socket_8_threads: metric_extractor_install volume_install false_sharing_write_inter_socket_run_8_threads false_sharing_write_inter_socket_extract_metrics_8_threads

false_sharing_write_inter_socket_extract_metrics_8_threads:
	dump_file="false_sharing_write_inter_socket_8_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_inter_socket_8_threads_$$i/ubench_write-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_inter_socket_8_threads_$$i/ubench_write-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_inter_socket_8_threads_$$i/ubench_write-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_inter_socket_8_threads_$$i/ubench_write-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_inter_socket_8_threads_$$i/ubench_write-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_inter_socket_8_threads_$$i/ubench_write-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_write_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_write_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

false_sharing_write_inter_socket_run_8_threads: 
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_write_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3 10 11 12 13\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_write_inter_socket_8_threads_$$i  ./write-volume/ubench_write -n 8 -s 1.0 -f $$i -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3 10 11 12 13" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_write_inter_socket_8_threads_$$i ./write-volume/ubench_write -n 8 -s 1.0 -f $$i -i 100000000 2>&1 | tee $$dump_file ;  \
        done

false_sharing_write_inter_socket_16_threads: metric_extractor_install volume_install false_sharing_write_inter_socket_run_16_threads false_sharing_write_inter_socket_extract_metrics_16_threads

false_sharing_write_inter_socket_extract_metrics_16_threads:
	dump_file="false_sharing_write_inter_socket_16_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_inter_socket_16_threads_$$i/ubench_write-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_inter_socket_16_threads_$$i/ubench_write-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_inter_socket_16_threads_$$i/ubench_write-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_inter_socket_16_threads_$$i/ubench_write-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_inter_socket_16_threads_$$i/ubench_write-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_write_inter_socket_16_threads_$$i/ubench_write-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_write_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_write_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

false_sharing_write_inter_socket_run_16_threads: 
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_write_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3 4 5 6 7 10 11 12 13 14 15 16 17\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_write_inter_socket_16_threads_$$i  ./write-volume/ubench_write -n 16 -s 1.0 -f $$i -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3 4 5 6 7 10 11 12 13 14 15 16 17" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_write_inter_socket_16_threads_$$i ./write-volume/ubench_write -n 16 -s 1.0 -f $$i -i 100000000 2>&1 | tee $$dump_file ;  \
        done

false_sharing_add_intra_socket: false_sharing_add_intra_socket_2_threads false_sharing_add_intra_socket_4_threads false_sharing_add_intra_socket_8_threads

false_sharing_add_intra_socket_2_threads: metric_extractor_install volume_install false_sharing_add_intra_socket_run_2_threads false_sharing_add_intra_socket_extract_metrics_2_threads

false_sharing_add_intra_socket_extract_metrics_2_threads:
	dump_file="false_sharing_add_intra_socket_2_threads_metrics.txt" ; \
	echo "intra core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_intra_socket_2_threads_$$i/ubench_add-*.log 0 >> $$dump_file ; \
	done ; \
	echo "intra thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_intra_socket_2_threads_$$i/ubench_add-*.log 1 >> $$dump_file ; \
	done ; \
	echo "intra core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_intra_socket_2_threads_$$i/ubench_add-*.log 2 >> $$dump_file ; \
	done ; \
	echo "intra thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_intra_socket_2_threads_$$i/ubench_add-*.log 3 >> $$dump_file ; \
	done ; \
	echo "intra core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_intra_socket_2_threads_$$i/ubench_add-*.log 4 >> $$dump_file ; \
	done ; \
	echo "intra thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_intra_socket_2_threads_$$i/ubench_add-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_add_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_add_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

false_sharing_add_intra_socket_run_2_threads: 
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_add_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_add_intra_socket_2_threads_$$i  ./write-volume/ubench_add -n 2 -s 1.0 -f $$i -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_add_intra_socket_2_threads_$$i ./write-volume/ubench_add -n 2 -s 1.0 -f $$i -i 100000000 2>&1 | tee $$dump_file ;  \
	done

false_sharing_add_intra_socket_4_threads: metric_extractor_install volume_install false_sharing_add_intra_socket_run_4_threads false_sharing_add_intra_socket_extract_metrics_4_threads

false_sharing_add_intra_socket_extract_metrics_4_threads:
	dump_file="false_sharing_add_intra_socket_4_threads_metrics.txt" ; \
	echo "intra core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_intra_socket_4_threads_$$i/ubench_add-*.log 0 >> $$dump_file ; \
	done ; \
	echo "intra thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_intra_socket_4_threads_$$i/ubench_add-*.log 1 >> $$dump_file ; \
	done ; \
	echo "intra core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_intra_socket_4_threads_$$i/ubench_add-*.log 2 >> $$dump_file ; \
	done ; \
	echo "intra thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_intra_socket_4_threads_$$i/ubench_add-*.log 3 >> $$dump_file ; \
	done ; \
	echo "intra core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_intra_socket_4_threads_$$i/ubench_add-*.log 4 >> $$dump_file ; \
	done ; \
	echo "intra thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_intra_socket_4_threads_$$i/ubench_add-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_add_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_add_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

false_sharing_add_intra_socket_run_4_threads: 
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_add_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_add_intra_socket_4_threads_$$i  ./write-volume/ubench_add -n 4 -s 1.0 -f $$i -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_add_intra_socket_4_threads_$$i ./write-volume/ubench_add -n 4 -s 1.0 -f $$i -i 100000000 2>&1 | tee $$dump_file ;  \
	done

false_sharing_add_intra_socket_8_threads: metric_extractor_install volume_install false_sharing_add_intra_socket_run_8_threads false_sharing_add_intra_socket_extract_metrics_8_threads

false_sharing_add_intra_socket_extract_metrics_8_threads:
	dump_file="false_sharing_add_intra_socket_8_threads_metrics.txt" ; \
	echo "intra core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_intra_socket_8_threads_$$i/ubench_add-*.log 0 >> $$dump_file ; \
	done ; \
	echo "intra thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_intra_socket_8_threads_$$i/ubench_add-*.log 1 >> $$dump_file ; \
	done ; \
	echo "intra core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_intra_socket_8_threads_$$i/ubench_add-*.log 2 >> $$dump_file ; \
	done ; \
	echo "intra thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_intra_socket_8_threads_$$i/ubench_add-*.log 3 >> $$dump_file ; \
	done ; \
	echo "intra core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_intra_socket_8_threads_$$i/ubench_add-*.log 4 >> $$dump_file ; \
	done ; \
	echo "intra thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_intra_socket_8_threads_$$i/ubench_add-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_add_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_add_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

false_sharing_add_intra_socket_run_8_threads: 
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_add_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3 4 5 6 7\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_add_intra_socket_8_threads_$$i  ./write-volume/ubench_add -n 8 -s 1.0 -f $$i -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3 4 5 6 7" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_add_intra_socket_8_threads_$$i ./write-volume/ubench_add -n 8 -s 1.0 -f $$i -i 100000000 2>&1 | tee $$dump_file ;  \
	done

false_sharing_add_inter_socket: false_sharing_add_inter_socket_2_threads false_sharing_add_inter_socket_4_threads false_sharing_add_inter_socket_8_threads false_sharing_add_inter_socket_16_threads

false_sharing_add_inter_socket_2_threads: metric_extractor_install volume_install false_sharing_add_inter_socket_run_2_threads false_sharing_add_inter_socket_extract_metrics_2_threads

false_sharing_add_inter_socket_extract_metrics_2_threads:
	dump_file="false_sharing_add_inter_socket_2_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_inter_socket_2_threads_$$i/ubench_add-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_inter_socket_2_threads_$$i/ubench_add-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_inter_socket_2_threads_$$i/ubench_add-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_inter_socket_2_threads_$$i/ubench_add-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_inter_socket_2_threads_$$i/ubench_add-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_inter_socket_2_threads_$$i/ubench_add-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_add_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_add_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

false_sharing_add_inter_socket_run_2_threads: 
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_add_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 10\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_add_inter_socket_2_threads_$$i  ./write-volume/ubench_add -n 2 -s 1.0 -f $$i -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 10" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_add_inter_socket_2_threads_$$i ./write-volume/ubench_add -n 2 -s 1.0 -f $$i -i 100000000 2>&1 | tee $$dump_file ;  \
	done

false_sharing_add_inter_socket_4_threads: metric_extractor_install volume_install false_sharing_add_inter_socket_run_4_threads false_sharing_add_inter_socket_extract_metrics_4_threads

false_sharing_add_inter_socket_extract_metrics_4_threads:
	dump_file="false_sharing_add_inter_socket_4_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_inter_socket_4_threads_$$i/ubench_add-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_inter_socket_4_threads_$$i/ubench_add-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_inter_socket_4_threads_$$i/ubench_add-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_inter_socket_4_threads_$$i/ubench_add-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_inter_socket_4_threads_$$i/ubench_add-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_inter_socket_4_threads_$$i/ubench_add-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_add_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_add_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

false_sharing_add_inter_socket_run_4_threads: 
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_add_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 10 11\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_add_inter_socket_4_threads_$$i  ./write-volume/ubench_add -n 4 -s 1.0 -f $$i -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 10 11" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_add_inter_socket_4_threads_$$i ./write-volume/ubench_add -n 4 -s 1.0 -f $$i -i 100000000 2>&1 | tee $$dump_file ;  \
        done

false_sharing_add_inter_socket_8_threads: metric_extractor_install volume_install false_sharing_add_inter_socket_run_8_threads false_sharing_add_inter_socket_extract_metrics_8_threads

false_sharing_add_inter_socket_extract_metrics_8_threads:
	dump_file="false_sharing_add_inter_socket_8_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_inter_socket_8_threads_$$i/ubench_add-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_inter_socket_8_threads_$$i/ubench_add-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_inter_socket_8_threads_$$i/ubench_add-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_inter_socket_8_threads_$$i/ubench_add-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_inter_socket_8_threads_$$i/ubench_add-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_inter_socket_8_threads_$$i/ubench_add-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_add_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_add_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

false_sharing_add_inter_socket_run_8_threads: 
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_add_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3 10 11 12 13\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_add_inter_socket_8_threads_$$i  ./write-volume/ubench_add -n 8 -s 1.0 -f $$i -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3 10 11 12 13" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_add_inter_socket_8_threads_$$i ./write-volume/ubench_add -n 8 -s 1.0 -f $$i -i 100000000 2>&1 | tee $$dump_file ;  \
        done

false_sharing_add_inter_socket_16_threads: metric_extractor_install volume_install false_sharing_add_inter_socket_run_16_threads false_sharing_add_inter_socket_extract_metrics_16_threads

false_sharing_add_inter_socket_extract_metrics_16_threads:
	dump_file="false_sharing_add_inter_socket_16_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_inter_socket_16_threads_$$i/ubench_add-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_inter_socket_16_threads_$$i/ubench_add-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_inter_socket_16_threads_$$i/ubench_add-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_inter_socket_16_threads_$$i/ubench_add-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_inter_socket_16_threads_$$i/ubench_add-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_add_inter_socket_16_threads_$$i/ubench_add-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_add_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_add_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

false_sharing_add_inter_socket_run_16_threads: 
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_add_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3 4 5 6 7 10 11 12 13 14 15 16 17\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_add_inter_socket_16_threads_$$i  ./write-volume/ubench_add -n 16 -s 1.0 -f $$i -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3 4 5 6 7 10 11 12 13 14 15 16 17" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_add_inter_socket_16_threads_$$i ./write-volume/ubench_add -n 16 -s 1.0 -f $$i -i 100000000 2>&1 | tee $$dump_file ;  \
	done

false_sharing_exchg_intra_socket: false_sharing_exchg_intra_socket_2_threads false_sharing_exchg_intra_socket_4_threads false_sharing_exchg_intra_socket_8_threads

false_sharing_exchg_intra_socket_2_threads: metric_extractor_install volume_install false_sharing_exchg_intra_socket_run_2_threads false_sharing_exchg_intra_socket_extract_metrics_2_threads

false_sharing_exchg_intra_socket_extract_metrics_2_threads:
	dump_file="false_sharing_exchg_intra_socket_2_threads_metrics.txt" ; \
	echo "intra core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_intra_socket_2_threads_$$i/ubench_exchg-*.log 0 >> $$dump_file ; \
	done ; \
	echo "intra thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_intra_socket_2_threads_$$i/ubench_exchg-*.log 1 >> $$dump_file ; \
	done ; \
	echo "intra core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_intra_socket_2_threads_$$i/ubench_exchg-*.log 2 >> $$dump_file ; \
	done ; \
	echo "intra thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_intra_socket_2_threads_$$i/ubench_exchg-*.log 3 >> $$dump_file ; \
	done ; \
	echo "intra core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_intra_socket_2_threads_$$i/ubench_exchg-*.log 4 >> $$dump_file ; \
	done ; \
	echo "intra thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_intra_socket_2_threads_$$i/ubench_exchg-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_exchg_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_exchg_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

false_sharing_exchg_intra_socket_run_2_threads: 
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_exchg_intra_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_exchg_intra_socket_2_threads_$$i  ./write-volume/ubench_exchg -n 2 -s 1.0 -f $$i -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_exchg_intra_socket_2_threads_$$i ./write-volume/ubench_exchg -n 2 -s 1.0 -f $$i -i 100000000 2>&1 | tee $$dump_file ;  \
	done

false_sharing_exchg_intra_socket_4_threads: metric_extractor_install volume_install false_sharing_exchg_intra_socket_run_4_threads false_sharing_exchg_intra_socket_extract_metrics_4_threads

false_sharing_exchg_intra_socket_extract_metrics_4_threads:
	dump_file="false_sharing_exchg_intra_socket_4_threads_metrics.txt" ; \
	echo "intra core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_intra_socket_4_threads_$$i/ubench_exchg-*.log 0 >> $$dump_file ; \
	done ; \
	echo "intra thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_intra_socket_4_threads_$$i/ubench_exchg-*.log 1 >> $$dump_file ; \
	done ; \
	echo "intra core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_intra_socket_4_threads_$$i/ubench_exchg-*.log 2 >> $$dump_file ; \
	done ; \
	echo "intra thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_intra_socket_4_threads_$$i/ubench_exchg-*.log 3 >> $$dump_file ; \
	done ; \
	echo "intra core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_intra_socket_4_threads_$$i/ubench_exchg-*.log 4 >> $$dump_file ; \
	done ; \
	echo "intra thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_intra_socket_4_threads_$$i/ubench_exchg-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_exchg_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_exchg_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

false_sharing_exchg_intra_socket_run_4_threads: 
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_exchg_intra_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_exchg_intra_socket_4_threads_$$i  ./write-volume/ubench_exchg -n 4 -s 1.0 -f $$i -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_exchg_intra_socket_4_threads_$$i ./write-volume/ubench_exchg -n 4 -s 1.0 -f $$i -i 100000000 2>&1 | tee $$dump_file ;  \
        done

false_sharing_exchg_intra_socket_8_threads: metric_extractor_install volume_install false_sharing_exchg_intra_socket_run_8_threads false_sharing_exchg_intra_socket_extract_metrics_8_threads

false_sharing_exchg_intra_socket_extract_metrics_8_threads:
	dump_file="false_sharing_exchg_intra_socket_8_threads_metrics.txt" ; \
	echo "intra core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_intra_socket_8_threads_$$i/ubench_exchg-*.log 0 >> $$dump_file ; \
	done ; \
	echo "intra thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_intra_socket_8_threads_$$i/ubench_exchg-*.log 1 >> $$dump_file ; \
	done ; \
	echo "intra core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_intra_socket_8_threads_$$i/ubench_exchg-*.log 2 >> $$dump_file ; \
	done ; \
	echo "intra thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_intra_socket_8_threads_$$i/ubench_exchg-*.log 3 >> $$dump_file ; \
	done ; \
	echo "intra core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_intra_socket_8_threads_$$i/ubench_exchg-*.log 4 >> $$dump_file ; \
	done ; \
	echo "intra thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_intra_socket_8_threads_$$i/ubench_exchg-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_exchg_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_exchg_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

false_sharing_exchg_intra_socket_run_8_threads: 
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_exchg_intra_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3 4 5 6 7\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_exchg_intra_socket_8_threads_$$i  ./write-volume/ubench_exchg -n 8 -s 1.0 -f $$i -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3 4 5 6 7" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_exchg_intra_socket_8_threads_$$i ./write-volume/ubench_exchg -n 8 -s 1.0 -f $$i -i 100000000 2>&1 | tee $$dump_file ;  \
	done

false_sharing_exchg_inter_socket: false_sharing_exchg_inter_socket_2_threads false_sharing_exchg_inter_socket_4_threads false_sharing_exchg_inter_socket_8_threads false_sharing_exchg_inter_socket_16_threads

false_sharing_exchg_inter_socket_2_threads: metric_extractor_install volume_install false_sharing_exchg_inter_socket_run_2_threads false_sharing_exchg_inter_socket_extract_metrics_2_threads

false_sharing_exchg_inter_socket_extract_metrics_2_threads:
	dump_file="false_sharing_exchg_inter_socket_2_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_inter_socket_2_threads_$$i/ubench_exchg-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_inter_socket_2_threads_$$i/ubench_exchg-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_inter_socket_2_threads_$$i/ubench_exchg-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_inter_socket_2_threads_$$i/ubench_exchg-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_inter_socket_2_threads_$$i/ubench_exchg-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_inter_socket_2_threads_$$i/ubench_exchg-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_exchg_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_exchg_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

false_sharing_exchg_inter_socket_run_2_threads: 
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_exchg_inter_socket_2_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 10\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_exchg_inter_socket_2_threads_$$i  ./write-volume/ubench_exchg -n 2 -s 1.0 -f $$i -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 10" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_exchg_inter_socket_2_threads_$$i ./write-volume/ubench_exchg -n 2 -s 1.0 -f $$i -i 100000000 2>&1 | tee $$dump_file ;  \
	done

false_sharing_exchg_inter_socket_4_threads: metric_extractor_install volume_install false_sharing_exchg_inter_socket_run_4_threads false_sharing_exchg_inter_socket_extract_metrics_4_threads

false_sharing_exchg_inter_socket_extract_metrics_4_threads:
	dump_file="false_sharing_exchg_inter_socket_4_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_inter_socket_4_threads_$$i/ubench_exchg-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_inter_socket_4_threads_$$i/ubench_exchg-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_inter_socket_4_threads_$$i/ubench_exchg-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_inter_socket_4_threads_$$i/ubench_exchg-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_inter_socket_4_threads_$$i/ubench_exchg-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_inter_socket_4_threads_$$i/ubench_exchg-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_exchg_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_exchg_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

false_sharing_exchg_inter_socket_run_4_threads: 
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_exchg_inter_socket_4_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 10 11\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_exchg_inter_socket_4_threads_$$i  ./write-volume/ubench_exchg -n 4 -s 1.0 -f $$i -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 10 11" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_exchg_inter_socket_4_threads_$$i ./write-volume/ubench_exchg -n 4 -s 1.0 -f $$i -i 100000000 2>&1 | tee $$dump_file ;  \
	done

false_sharing_exchg_inter_socket_8_threads: metric_extractor_install volume_install false_sharing_exchg_inter_socket_run_8_threads false_sharing_exchg_inter_socket_extract_metrics_8_threads

false_sharing_exchg_inter_socket_extract_metrics_8_threads:
	dump_file="false_sharing_exchg_inter_socket_8_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_inter_socket_8_threads_$$i/ubench_exchg-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_inter_socket_8_threads_$$i/ubench_exchg-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_inter_socket_8_threads_$$i/ubench_exchg-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_inter_socket_8_threads_$$i/ubench_exchg-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_inter_socket_8_threads_$$i/ubench_exchg-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_inter_socket_8_threads_$$i/ubench_exchg-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_exchg_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_exchg_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

false_sharing_exchg_inter_socket_run_8_threads: 
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_exchg_inter_socket_8_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3 10 11 12 13\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_exchg_inter_socket_8_threads_$$i  ./write-volume/ubench_exchg -n 8 -s 1.0 -f $$i -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3 10 11 12 13" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_exchg_inter_socket_8_threads_$$i ./write-volume/ubench_exchg -n 8 -s 1.0 -f $$i -i 100000000 2>&1 | tee $$dump_file ;  \
	done

false_sharing_exchg_inter_socket_16_threads: metric_extractor_install volume_install false_sharing_exchg_inter_socket_run_16_threads false_sharing_exchg_inter_socket_extract_metrics_16_threads

false_sharing_exchg_inter_socket_extract_metrics_16_threads:
	dump_file="false_sharing_exchg_inter_socket_16_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_inter_socket_16_threads_$$i/ubench_exchg-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_inter_socket_16_threads_$$i/ubench_exchg-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_inter_socket_16_threads_$$i/ubench_exchg-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_inter_socket_16_threads_$$i/ubench_exchg-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_inter_socket_16_threads_$$i/ubench_exchg-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count false_sharing_exchg_inter_socket_16_threads_$$i/ubench_exchg-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_exchg_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_exchg_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		echo $$input_file ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

false_sharing_exchg_inter_socket_run_16_threads: 
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="false_sharing_exchg_inter_socket_16_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3 4 5 6 7 10 11 12 13 14 15 16 17\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_exchg_inter_socket_16_threads_$$i  ./write-volume/ubench_exchg -n 16 -s 1.0 -f $$i -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3 4 5 6 7 10 11 12 13 14 15 16 17" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o false_sharing_exchg_inter_socket_16_threads_$$i ./write-volume/ubench_exchg -n 16 -s 1.0 -f $$i -i 100000000 2>&1 | tee $$dump_file ;  \
	done

p2p: metric_extractor_install p2p_install p2p_run p2p_extract_metrics

p2p_run:
	GOMP_CPU_AFFINITY="0 1 2 3" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o p2p_run_0_1 ./read-write-p2p/ubench -g 2 -n 4 -s 0.0 1.0 -d 2 2 -t 0 1 2 3 -i 100000000 2>&1 | tee p2p_0_1_stdout.txt
	GOMP_CPU_AFFINITY="0 1 2 3" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o p2p_run_01_09 ./read-write-p2p/ubench -g 2 -n 4 -s 0.1 0.9 -d 2 2 -t 0 1 2 3 -i 100000000 2>&1 | tee p2p_01_09_stdout.txt
	GOMP_CPU_AFFINITY="0 1 2 3" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o p2p_run_02_08 ./read-write-p2p/ubench -g 2 -n 4 -s 0.2 0.8 -d 2 2 -t 0 1 2 3 -i 100000000 2>&1 | tee p2p_02_08_stdout.txt
	GOMP_CPU_AFFINITY="0 1 2 3" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o p2p_run_03_07 ./read-write-p2p/ubench -g 2 -n 4 -s 0.3 0.7 -d 2 2 -t 0 1 2 3 -i 100000000 2>&1 | tee p2p_03_07_stdout.txt
	GOMP_CPU_AFFINITY="0 1 2 3" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o p2p_run_04_06 ./read-write-p2p/ubench -g 2 -n 4 -s 0.4 0.6 -d 2 2 -t 0 1 2 3 -i 100000000 2>&1 | tee p2p_04_06_stdout.txt
	GOMP_CPU_AFFINITY="0 1 2 3" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o p2p_run_05_05 ./read-write-p2p/ubench -g 2 -n 4 -s 0.5 0.5 -d 2 2 -t 0 1 2 3 -i 100000000 2>&1 | tee p2p_05_05_stdout.txt
	GOMP_CPU_AFFINITY="0 1 2 3" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o p2p_run_06_04 ./read-write-p2p/ubench -g 2 -n 4 -s 0.6 0.4 -d 2 2 -t 0 1 2 3 -i 100000000 2>&1 | tee p2p_06_04_stdout.txt
	GOMP_CPU_AFFINITY="0 1 2 3" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o p2p_run_07_03 ./read-write-p2p/ubench -g 2 -n 4 -s 0.7 0.3 -d 2 2 -t 0 1 2 3 -i 100000000 2>&1 | tee p2p_07_03_stdout.txt
	GOMP_CPU_AFFINITY="0 1 2 3" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o p2p_run_08_02 ./read-write-p2p/ubench -g 2 -n 4 -s 0.8 0.2 -d 2 2 -t 0 1 2 3 -i 100000000 2>&1 | tee p2p_08_02_stdout.txt
	GOMP_CPU_AFFINITY="0 1 2 3" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o p2p_run_09_01 ./read-write-p2p/ubench -g 2 -n 4 -s 0.9 0.1 -d 2 2 -t 0 1 2 3 -i 100000000 2>&1 | tee p2p_09_01_stdout.txt
	GOMP_CPU_AFFINITY="0 1 2 3" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o p2p_run_1_0 ./read-write-p2p/ubench -g 2 -n 4 -s 1.0 0.0 -d 2 2 -t 0 1 2 3 -i 100000000 2>&1 | tee p2p_1_0_stdout.txt

p2p_extract_metrics:
	dump_file="p2p_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_0_1/ubench-*.log 0 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_01_09/ubench-*.log 0 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_02_08/ubench-*.log 0 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_03_07/ubench-*.log 0 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_04_06/ubench-*.log 0 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_05_05/ubench-*.log 0 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_06_04/ubench-*.log 0 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_07_03/ubench-*.log 0 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_08_02/ubench-*.log 0 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_09_01/ubench-*.log 0 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_1_0/ubench-*.log 0 >> $$dump_file ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_0_1/ubench-*.log 1 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_01_09/ubench-*.log 1 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_02_08/ubench-*.log 1 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_03_07/ubench-*.log 1 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_04_06/ubench-*.log 1 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_05_05/ubench-*.log 1 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_06_04/ubench-*.log 1 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_07_03/ubench-*.log 1 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_08_02/ubench-*.log 1 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_09_01/ubench-*.log 1 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_1_0/ubench-*.log 1 >> $$dump_file ; \
	echo "inter core true sharing" >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_0_1/ubench-*.log 2 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_01_09/ubench-*.log 2 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_02_08/ubench-*.log 2 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_03_07/ubench-*.log 2 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_04_06/ubench-*.log 2 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_05_05/ubench-*.log 2 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_06_04/ubench-*.log 2 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_07_03/ubench-*.log 2 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_08_02/ubench-*.log 2 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_09_01/ubench-*.log 2 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_1_0/ubench-*.log 2 >> $$dump_file ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_0_1/ubench-*.log 3 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_01_09/ubench-*.log 3 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_02_08/ubench-*.log 3 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_03_07/ubench-*.log 3 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_04_06/ubench-*.log 3 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_05_05/ubench-*.log 3 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_06_04/ubench-*.log 3 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_07_03/ubench-*.log 3 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_08_02/ubench-*.log 3 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_09_01/ubench-*.log 3 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_1_0/ubench-*.log 3 >> $$dump_file ; \
	echo "inter core false sharing" >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_0_1/ubench-*.log 4 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_01_09/ubench-*.log 4 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_02_08/ubench-*.log 4 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_03_07/ubench-*.log 4 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_04_06/ubench-*.log 4 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_05_05/ubench-*.log 4 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_06_04/ubench-*.log 4 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_07_03/ubench-*.log 4 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_08_02/ubench-*.log 4 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_09_01/ubench-*.log 4 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_1_0/ubench-*.log 4 >> $$dump_file ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_0_1/ubench-*.log 5 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_01_09/ubench-*.log 5 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_02_08/ubench-*.log 5 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_03_07/ubench-*.log 5 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_04_06/ubench-*.log 5 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_05_05/ubench-*.log 5 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_06_04/ubench-*.log 5 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_07_03/ubench-*.log 5 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_08_02/ubench-*.log 5 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_09_01/ubench-*.log 5 >> $$dump_file ; \
	./metric_extractor/extract_communication_count p2p_run_1_0/ubench-*.log 5 >> $$dump_file ; \
	echo "elapsed time" >> $$dump_file ; \
	./metric_extractor/extract_overhead p2p_0_1_stdout.txt 0 >> $$dump_file ; \
	./metric_extractor/extract_overhead p2p_01_09_stdout.txt 0 >> $$dump_file ; \
	./metric_extractor/extract_overhead p2p_02_08_stdout.txt 0 >> $$dump_file ; \
	./metric_extractor/extract_overhead p2p_03_07_stdout.txt 0 >> $$dump_file ; \
	./metric_extractor/extract_overhead p2p_04_06_stdout.txt 0 >> $$dump_file ; \
	./metric_extractor/extract_overhead p2p_05_05_stdout.txt 0 >> $$dump_file ; \
	./metric_extractor/extract_overhead p2p_06_04_stdout.txt 0 >> $$dump_file ; \
	./metric_extractor/extract_overhead p2p_07_03_stdout.txt 0 >> $$dump_file ; \
	./metric_extractor/extract_overhead p2p_08_02_stdout.txt 0 >> $$dump_file ; \
	./metric_extractor/extract_overhead p2p_09_01_stdout.txt 0 >> $$dump_file ; \
	./metric_extractor/extract_overhead p2p_1_0_stdout.txt 0 >> $$dump_file ; \
	echo "memory overhead" >> $$dump_file ; \
	./metric_extractor/extract_overhead p2p_0_1_stdout.txt 1 >> $$dump_file ; \
	./metric_extractor/extract_overhead p2p_01_09_stdout.txt 1 >> $$dump_file ; \
	./metric_extractor/extract_overhead p2p_02_08_stdout.txt 1 >> $$dump_file ; \
	./metric_extractor/extract_overhead p2p_03_07_stdout.txt 1 >> $$dump_file ; \
	./metric_extractor/extract_overhead p2p_04_06_stdout.txt 1 >> $$dump_file ; \
	./metric_extractor/extract_overhead p2p_05_05_stdout.txt 1 >> $$dump_file ; \
	./metric_extractor/extract_overhead p2p_06_04_stdout.txt 1 >> $$dump_file ; \
	./metric_extractor/extract_overhead p2p_07_03_stdout.txt 1 >> $$dump_file ; \
	./metric_extractor/extract_overhead p2p_08_02_stdout.txt 1 >> $$dump_file ; \
	./metric_extractor/extract_overhead p2p_09_01_stdout.txt 1 >> $$dump_file ; \
	./metric_extractor/extract_overhead p2p_1_0_stdout.txt 1 >> $$dump_file ;

read_write: read_write_2_threads read_write_4_threads read_write_8_threads

read_write_2_threads: metric_extractor_install p2p_install read_write_2_threads_run read_write_2_threads_extract_metrics

read_write_2_threads_extract_metrics:
	dump_file="read_write_2_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count read_write_2_threads_$$i/ubench-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count read_write_2_threads_$$i/ubench-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count read_write_2_threads_$$i/ubench-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count read_write_2_threads_$$i/ubench-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count read_write_2_threads_$$i/ubench-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count read_write_2_threads_$$i/ubench-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="read_write_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="read_write_2_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

read_write_2_threads_run:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="read_write_2_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o read_write_2_threads_$$i ./read-write-p2p/ubench -g 1 -n 2 -s 1.0 -d 2 -t 0 1 -r 0.0 $$i -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o read_write_2_threads_$$i ./read-write-p2p/ubench -g 1 -n 2 -s 1.0 -d 2 -t 0 1 -r 0.0 $$i -i 100000000 2>&1 | tee $$dump_file ;  \
	done

read_write_4_threads: metric_extractor_install p2p_install read_write_4_threads_run read_write_4_threads_extract_metrics

read_write_4_threads_extract_metrics:
	dump_file="read_write_4_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count read_write_4_threads_$$i/ubench-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count read_write_4_threads_$$i/ubench-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count read_write_4_threads_$$i/ubench-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count read_write_4_threads_$$i/ubench-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count read_write_4_threads_$$i/ubench-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count read_write_4_threads_$$i/ubench-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="read_write_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="read_write_4_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

read_write_4_threads_run:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="read_write_4_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o read_write_4_threads_$$i ./read-write-p2p/ubench -g 1 -n 4 -s 1.0 -d 4 -t 0 1 2 3 -r 0.0 $$i $$i $$i -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o read_write_4_threads_$$i ./read-write-p2p/ubench -g 1 -n 4 -s 1.0 -d 4 -t 0 1 2 3 -r 0.0 $$i $$i $$i -i 100000000 2>&1 | tee $$dump_file ;  \
	done

read_write_8_threads: metric_extractor_install p2p_install read_write_8_threads_run read_write_8_threads_extract_metrics

read_write_8_threads_extract_metrics:
	dump_file="read_write_8_threads_metrics.txt" ; \
	echo "inter core all sharing" > $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count read_write_8_threads_$$i/ubench-*.log 0 >> $$dump_file ; \
	done ; \
	echo "inter thread all sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count read_write_8_threads_$$i/ubench-*.log 1 >> $$dump_file ; \
	done ; \
	echo "inter core true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count read_write_8_threads_$$i/ubench-*.log 2 >> $$dump_file ; \
	done ; \
	echo "inter thread true sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count read_write_8_threads_$$i/ubench-*.log 3 >> $$dump_file ; \
	done ; \
	echo "inter core false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count read_write_8_threads_$$i/ubench-*.log 4 >> $$dump_file ; \
	done ; \
	echo "inter thread false sharing" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		./metric_extractor/extract_communication_count read_write_8_threads_$$i/ubench-*.log 5 >> $$dump_file ; \
	done ; \
	echo "elapsed time" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="read_write_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_overhead $$input_file 0 >> $$dump_file ; \
	done ; \
	echo "memory overhead" >> $$dump_file ; \
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="read_write_8_threads_" ; \
		string2="_stdout.txt" ; \
		input_file="$$string1$$i$$string2" ; \
		./metric_extractor/extract_overhead $$input_file 1 >> $$dump_file ; \
	done ;

read_write_8_threads_run:
	for i in 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0; do \
		string1="read_write_8_threads_" ; \
		string2="_stdout.txt" ; \
		dump_file="$$string1$$i$$string2" ; \
		echo "GOMP_CPU_AFFINITY=\"0 1 2 3 4 5 6 7\" /usr/bin/time -f \"Elapsed Time , %e, system, %S, user, %U, memory, %M\" ${ComDetective_bin}/bin/ComDetectiverun -o read_write_8_threads_$$i ./read-write-p2p/ubench -g 1 -n 8 -s 1.0 -d 8 -t 0 1 2 3 4 5 6 7 -r 0.0 $$i $$i $$i $$i $$i $$i $$i -i 100000000"  ;  \
		GOMP_CPU_AFFINITY="0 1 2 3 4 5 6 7" /usr/bin/time -f "Elapsed Time , %e, system, %S, user, %U, memory, %M" ${ComDetective_bin}/bin/ComDetectiverun -o read_write_8_threads_$$i ./read-write-p2p/ubench -g 1 -n 8 -s 1.0 -d 8 -t 0 1 2 3 4 5 6 7 -r 0.0 $$i $$i $$i $$i $$i $$i $$i -i 100000000 2>&1 | tee $$dump_file ;  \
	done

metric_extractor_install:
	cd metric_extractor && make

metric_extractor_clean:
	cd metric_extractor && make clean

volume_install:	volume_write_install volume_add_install volume_exchg_install

volume_write_install:
	cd write-volume && make ubench_write 

volume_add_install:
	cd write-volume && make ubench_add

volume_exchg_install:
	cd write-volume && make ubench_exchg

volume_clean: 
	cd write-volume && rm ubench_*

p2p_install:
	cd read-write-p2p && make ubench

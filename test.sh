#!/bin/bash

for f  in *.test ; do
		runtest.sh $f
		valgrind $f
done

					

		

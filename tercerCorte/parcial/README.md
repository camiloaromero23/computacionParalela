# Final test #3

> Take into account that all the following commands have to be run on the root directory of this repo.

To execute and get the profiling file, run the following commands:

``` console
make
python3 -m cProfile -o outputs/profile_{ext_name}.dat
```

> For correctly profiling Cython or Python implementations, it is important to ***comment/uncomment*** the lines ***#50/51*** of the ***heat_main.py*** file depending on which one you are going to work with (They're mutually exclusive)

To profile, run the following command:

``` console
python3 -m pstats outputs/profile_{ext_name}.dat
```

Inside the profiling cli, run the following commands to correctly profile your execution:

``` console
strip
sort cumtime
stats {#output_calls}
```

To clean workspace run the following command:

``` console
make clean
```

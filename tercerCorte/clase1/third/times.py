from timeit import repeat
from subprocess import check_output


def time(arg, num_iter, name, module):
    statement = "%s(%s)" % (name, arg)
    setup = "from %s import %s" % (module, name)
    time = min(repeat(stmt=statement, setup=setup,
               number=num_iter))/float(num_iter)*1e9
    return time


N = 10**3

# 0

py_time_0 = time(0, N, name='fib', module='fib')
cy_time_0 = time(0, N, name='fib', module='cyfib')
ctime_0 = float(check_output(('./cfib.x 0 %d' % (N)).split()))
# c_time_0 = time(0,N,name='fib',module='cyfib')

py0SpeedUp = 1.0
cy0SpeedUp = py_time_0 / cy_time_0
c_0SpeedUp = py_time_0 / ctime_0

py_time_90 = time(90, N, name='fib', module='fib')
cy_time_90 = time(90, N, name='fib', module='cyfib')
ctime_90 = float(check_output(('./cfib.x 90 %d' % (N)).split()))

py90SpeedUp = 1.0
cy90SpeedUp = py_time_90 / cy_time_90
c_90SpeedUp = py_time_90 / ctime_90


data_format = "{:s},{:f},{:f},{:f},{:f}\n"

with open("fiboTimeSp.csv", 'w') as fh:
    fh.write('Version,fib(0) [ns],SpeedUp,fib(90) [ns],SpeedUp\n')
    fh.write(data_format.format("Python", py_time_0,
             py0SpeedUp, py_time_90, py90SpeedUp))
    fh.write(data_format.format("Cython", cy_time_0,
             cy0SpeedUp, cy_time_90, cy90SpeedUp))
    fh.write(data_format.format("C", ctime_0,
             c_0SpeedUp, ctime_90, c_90SpeedUp))

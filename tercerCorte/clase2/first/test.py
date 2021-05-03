import gravity
import cy_gravity
import time

# Init planet
earth = gravity.Planet()
earth.x = 100 * 10**3
earth.y = 300 * 10**3
earth.z = 700 * 10**3
earth.vx = 2.000 * 10**3
earth.vy = 29.870 * 10**3
earth.vz = 0.034 * 10**3
earth.m = 5.9742 * 10**24

cy_earth = cy_gravity.Planet()
cy_earth.x = 100 * 10**3
cy_earth.y = 300 * 10**3
cy_earth.z = 700 * 10**3
cy_earth.vx = 2.000 * 10**3
cy_earth.vy = 29.870 * 10**3
cy_earth.vz = 0.034 * 10**3
cy_earth.m = 5.9742 * 10**24

time_span = 400
n_steps = 2000000

start = time.time()

gravity.step_time(earth, time_span, n_steps)

total_time = time.time() - start

start = time.time()
cy_gravity.step_time(cy_earth, time_span, n_steps)
cy_total_time = time.time() - start

speedUp = round(total_time/cy_total_time, 3)
print("Python time: {} \n".format(total_time))
print("Cython time: {} \n".format(cy_total_time))
print("SpeedUp: {} \n".format(speedUp))

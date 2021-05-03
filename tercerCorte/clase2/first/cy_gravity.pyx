#cython: language_level=3
cimport cython

cdef extern from "math.h":
    double sqrt(double x) nogil

cdef class Planet(object):
    cdef public double x,y,z,vx,vy,vz,m

    def __init__(self):
        # Some position and initial velocity
        self.x = 1.0
        self.y = 0.0
        self.z = 0.0
        self.vx = 0.0
        self.vy = 0.5
        self.vz = 0.0

        # Mass
        self.m = 1.0


@cython.cdivision(True)
cdef void single_step(Planet planet, double dt) nogil:
    """Next step on time"""

    # Force calculation
    cdef double distance, Fx, Fy, Fz
    distance = sqrt(planet.x**2 + planet.y**2 + planet.z**2)
    Fx = -planet.x/distance**3
    Fy = -planet.y/distance**3
    Fz = -planet.z/distance**3

    # Time step of position by velocity
    planet.x += dt*planet.vx
    planet.y += dt*planet.vy
    planet.z += dt*planet.vz

    # Time step of speed by force and mass
    planet.vx += dt*Fx/planet.m
    planet.vy += dt*Fy/planet.m
    planet.vz += dt*Fz/planet.m

def step_time(Planet planet, double time_span, int n_steps):
    cdef double dt
    cdef int i 
    dt = time_span / n_steps

    with nogil:
        for i in range(n_steps):
            single_step(planet, dt)

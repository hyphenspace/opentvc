#!/usr/bin/env python3
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import argparse

parser = argparse.ArgumentParser(description='Runs a flight simulation.')
parser.add_argument('--final_mass', type=float, default=0.9, help='The rockets total dry weight without the motor. This value is in kg.')
parser.add_argument('--propellant_mass', type=float, default=0.06, help='The weight of the propellant from the rockets motor. This value is in kg.')
parser.add_argument('--motor_mass', type=float, default=0.09, help='The total weight of the rockets motor. This value is in kg.')
args = parser.parse_args()

data = pd.read_csv('F15-0.csv')
meters_per_seconds_squared = [] # change in velocity per time
meter_per_seconds = []

def rocket_equation(final_mass=args.final_mass, motor_mass=args.motor_mass, propellant_mass=args.propellant_mass):
    delta_motor_mass = (motor_mass - propellant_mass) + propellant_mass 
    initial_mass = final_mass + delta_motor_mass
    print(f'Initial mass: {initial_mass}')
    thrust = data[['Thrust(N)']].to_numpy() # 1N = 1 kg * m / s^2
    delta_time = data[['Time(Sec)']].to_numpy() # time in seconds that has passed since the last frame
    
    for i in range(len(thrust)):
        if propellant_mass != 0.00:
            propellant_mass = round(propellant_mass - 0.01, 2)
            delta_motor_mass = (motor_mass - args.propellant_mass) + propellant_mass # 90 grams of Total Motor Mass
            initial_mass = final_mass + delta_motor_mass
        meters_per_seconds_squared.append(thrust[i] / round(initial_mass, 2))
        acceleration = np.asarray(meters_per_seconds_squared)

        meter_per_seconds.append(acceleration[i] * delta_time[i])
        velocity = np.asarray(meter_per_seconds)
    
    print(f'Final mass: {initial_mass}')
    print(delta_motor_mass)

    # Plotting rockets acceleration.
    plt.subplot(2, 1, 1)
    plt.title('Vehicles acceleration on F15-0')
    plt.tight_layout(pad=5.0)
    plt.plot(delta_time, acceleration)
    plt.xlabel('Time in seconds (s)')
    plt.ylabel('Acceleration (m/s^2)')

    # Plotting rockets velocity
    plt.subplot(2, 1, 2)
    plt.title('Vehicles velocity on F15-0')
    plt.plot(delta_time, velocity)
    plt.xlabel('Time in seconds (s)')
    plt.ylabel('Velocity (m/s)')
    plt.show()


if __name__ == '__main__':
    rocket_equation()

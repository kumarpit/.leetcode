#######################################################
## Problem Statement
#######################################################

# I own a parking lot that can hold up to ’n’ cars at any given point in time. Each slot is given a number starting at 1 increasing with increasing distance from the entry point in steps of one. I want to create an automated ticketing system that allows my customers to use my parking lot without human intervention.

# When a car enters my parking lot, I want to have a ticket issued to the driver. The ticket issuing process includes us documenting the registration number (number plate) and the color of the car and allocating an available parking slot to the car before actually handing over a ticket to the driver (we assume that our customers are nice enough to always park in the slots allocated to them). The customer should be allocated a parking slot that is nearest to the entry. At the exit, the customer returns the ticket which then marks the slot they were using as being available.

# Due to government regulation, the system should provide me with the ability to find out:
# ● Registration numbers of all cars of a particular color.
# ● Slot number in which a car with a given registration number is parked.
# ● Slot numbers of all slots where a car of a particular color is parked.

# We interact with the system via a simple set of commands which produce a specific output. Please take a look at the example below, which includes all the commands you need to support — they’re self-explanatory. The system should allow input in two ways. Just to clarify, the same codebase should support both modes of input. we don’t want two distinct submissions.
# 1) It should provide us with an interactive command prompt based shell where commands can be typed in
# 2) It should accept a filename as a parameter at the command prompt and read the commands from that file

# ---------------------------------------------------------------------

# Parking Lot
#    - Ticket
#       - Car
#           - License Plate Number
#           - Color
#       - Slot 
#           - Index

# ● Registration numbers of all cars of a particular color.
# ● Slot number in which a car with a given registration number is parked.
# ● Slot numbers of all slots where a car of a particular color is parked.


#######################################################
## Implementation
#######################################################

import argparse
from parking_lot import ParkingLot
from vehicle import Vehicle
from parking_ticket import ParkingTicket
from typing import Optional

# Command definitions

def park(parking_lot, args):
    parking_ticket: Optional[ParkingTicket] = parking_lot.park(Vehicle(args.registration, args.color))
    
    if parking_ticket is None:
        print("Sorry, parking lot is full")
        return

    print(f"Allocated slot number: {parking_ticket.slot.index}")

def leave(parking_lot, args):
    parking_lot.leave(args.index)
    print(f"Slot number {args.index} is free")

def status(parking_lot, _):
    parking_lot.print_status()

def registration_numbers_for_vehicles_with_color(parking_lot, args):
    print(parking_lot.get_registration_numbers_for_vehicles_with_color(args.color))

def slot_numbers_for_vehicles_with_color(parking_lot, args):
    print(parking_lot.get_slot_numbers_for_vehicles_with_color(args.color))

def slot_number_for_vehicle_with_registration(parking_lot, args):
    print(parking_lot.get_slot_number_for_vehicle_with_registration(args.registration))

# Parking Lot REPL

def setup_parser():
    parser = argparse.ArgumentParser(description="Parking Lot CLI Tool")
    subparsers = parser.add_subparsers(dest='command')

    create_parking_lot_parser = subparsers.add_parser('create_parking_lot', help="Initializes a parking lot with positive, non-zero slots")
    create_parking_lot_parser.add_argument('num_slots', type=int)
    
    park_parser = subparsers.add_parser('park', help='Parks a vehicle in the nearest slot')
    park_parser.set_defaults(func=park)
    park_parser.add_argument('registration', type=str)
    park_parser.add_argument('color', type=str)

    leave_parser = subparsers.add_parser('leave', help="Vacates the given parking slot")
    leave_parser.set_defaults(func=leave)
    leave_parser.add_argument('index', type=int)
    
    status_parser = subparsers.add_parser('status', help="Prints information on all parked vehicles in this parking lot")
    status_parser.set_defaults(func=status)
    
    registration_numbers_for_vehicles_with_color_parser = subparsers.add_parser('registration_numbers_for_vehicles_with_color', help="Gets the registration numbers of all parked colors that have the given color")
    registration_numbers_for_vehicles_with_color_parser.set_defaults(func=registration_numbers_for_vehicles_with_color)
    registration_numbers_for_vehicles_with_color_parser.add_argument('color', type=str)
    
    slot_numbers_for_vehicles_with_color_parser = subparsers.add_parser('slot_numbers_for_vehicles_with_color', help="Gets the slot numbers of all parked colors that have the given color")
    slot_numbers_for_vehicles_with_color_parser.set_defaults(func=slot_numbers_for_vehicles_with_color)
    slot_numbers_for_vehicles_with_color_parser.add_argument('color', type=str)
    
    slot_number_for_vehicles_with_registration_parser = subparsers.add_parser('slot_number_for_vehicle_with_registration', help="Gets the slot number for the vehicle with the given registration")
    slot_number_for_vehicles_with_registration_parser.set_defaults(func=slot_number_for_vehicle_with_registration)
    slot_number_for_vehicles_with_registration_parser.add_argument('registration', type=str)
    
    return parser

def repl():
    parser = setup_parser()
    parking_lot: Optional[ParkingLot] = None
    while True:
        user_input = input(">>> ")
        if user_input.strip().lower() == 'exit':
            break
        try:
            args = parser.parse_args(user_input.split())
            if args.command and args.command == 'create_parking_lot':
                if parking_lot is not None:
                    raise Exception("Parking lot has already been initialized")
                num_slots = args.num_slots
                if num_slots <= 0:
                    raise ValueError("Number of slots must be a positive, non-zero integer")

                parking_lot = ParkingLot(num_slots)
                continue;

            if args.command:
                if parking_lot is None:
                    raise Exception("Parking lot has not been initialized")
                args.func(parking_lot, args)
                continue;
            
            else:
                print("Missing command")
        except Exception as e:
            print(e)

repl()

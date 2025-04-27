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
from parking_slot import ParkingSlot
from vehicle import Vehicle
from parking_ticket import ParkingTicket
from enum import Enum
from typing import List

class State(Enum):
    PARKING_LOT = 1

# Command definitions

def park(state, args):
    if State.PARKING_LOT.name not in state:
        raise Exception("Parking lot not initialized")

    parking_lot: ParkingLot = state[State.PARKING_LOT.name]
    parking_ticket: ParkingTicket | None = parking_lot.park(Vehicle(args.registration, args.color))
    
    if parking_ticket is None:
        print("Sorry, parking lot is full")
        return

    print(f"Allocated slot number: {parking_ticket.slot.index}")

def create_parking_lot(state, args):
    if State.PARKING_LOT.name in state:
        raise Exception("Parking lot already initialized")

    num_slots = args.num_slots
    if num_slots <= 0:
        raise Exception("Number of slots must be a positive, non-zero integer")

    state[State.PARKING_LOT.name] = ParkingLot(num_slots)

def leave(state, args):
    if State.PARKING_LOT.name not in state:
        raise Exception("Parking lot not initialized")

    slots: List[ParkingSlot] = state[State.PARKING_LOT.name].slots
    slot_to_free_index = args.index - 1
    
    if slot_to_free_index < 0 or slot_to_free_index >= len(slots):
        raise Exception("Invalid slot index")

    slot_to_free: ParkingSlot = slots[slot_to_free_index]
    slot_to_free.vacate()
    print(f"Slot number {slot_to_free.index} is free")

def status(state, args):
    print("not implemented")

def registration_numbers_for_cars_with_color(state, args):
    print("not implemented")

def slot_numbers_for_cars_with_color(state, args):
    print("not implemented")

def slot_number_for_car_with_registration(state, args):
    print("not implemented")

# Parking Lot REPL

def setup_parser():
    parser = argparse.ArgumentParser(description="Parking Lot CLI Tool")
    subparsers = parser.add_subparsers(dest='command')

    create_parking_lot_parser = subparsers.add_parser('create_parking_lot', help="Initializes a parking lot with positive, non-zero slots")
    create_parking_lot_parser.set_defaults(func=create_parking_lot)
    create_parking_lot_parser.add_argument('num_slots', type=int)
    
    park_parser = subparsers.add_parser('park', help='Parks a vehicle in the nearest slot')
    park_parser.set_defaults(func=park)
    park_parser.add_argument('registration', type=str)
    park_parser.add_argument('color', type=str)

    leave_parser = subparsers.add_parser('leave', help="Vacates the given parking slot")
    leave_parser .set_defaults(func=leave)
    leave_parser .add_argument('index', type=int)
    
    return parser

def repl():
    parser = setup_parser()
    state = {}
    while True:
        user_input = input(">>> ")
        if user_input.strip().lower() == 'exit':
            break
        try:
            args = parser.parse_args(user_input.split())
            if args.command:
                args.func(state, args)
            else:
                print("Missing command")
        except Exception as e:
            print(e)

repl()

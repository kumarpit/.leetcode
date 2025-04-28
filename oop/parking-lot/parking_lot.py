from parking_slot import ParkingSlot
from vehicle import Vehicle
from parking_ticket import ParkingTicket
from typing import Optional, Callable, cast

class ParkingLot:
    def __init__(self, num_slots: int):
        self.slots = [ParkingSlot(i) for i in range(1, num_slots + 1)]
        print(f"Created a parking lot with {num_slots} slots")

    def park(self, vehicle: Vehicle) -> Optional[ParkingTicket]:
        slot = self.__find_slot()
        if slot is not None:
            slot.occupy(vehicle)
            return ParkingTicket(vehicle, slot)
        
        return None

    def leave(self, slot_index: int) -> None:
        if slot_index < 1 or slot_index > len(self.slots):
            raise Exception("Slot index out of range")
        slot_to_free: ParkingSlot = self.slots[slot_index - 1] # slot_index is 1-indexed
        slot_to_free.vacate()

    def print_status(self) -> None:
        H_SPACER = lambda x : " " * x
        print("Slot No." + H_SPACER(5) + "Registration No." + H_SPACER(5) + "Color")
        for slot in self.slots:
            if not slot.is_empty:
                assert slot.occupant is not None
                print(str(slot.index) + H_SPACER(15) + slot.occupant.registration + H_SPACER(15) + slot.occupant.color)

    def get_registration_numbers_for_vehicles_with_color(self, color):
        pred: Callable[[ParkingSlot], bool] = lambda slot : cast(Vehicle, slot.occupant).color == color
        extract: Callable[[ParkingSlot], str] = lambda slot : cast(Vehicle, slot.occupant).registration
        return self.__filter_parked_vehicles_and_get(pred, extract)

    def get_slot_numbers_for_vehicles_with_color(self, color):
        pred: Callable[[ParkingSlot], bool] = lambda slot : cast(Vehicle, slot.occupant).color == color
        extract: Callable[[ParkingSlot], int] = lambda slot : slot.index
        return self.__filter_parked_vehicles_and_get(pred, extract)

    def get_slot_number_for_vehicle_with_registration(self, registration: str) -> Optional[int]:
        for slot in self.slots:
            if not slot.is_empty:
                if cast(Vehicle, slot.occupant).registration == registration:
                    return slot.index
        return None

    def __filter_parked_vehicles_and_get(self, pred: Callable[[ParkingSlot], bool], extract):
        result = []
        for slot in self.slots:
            if not slot.is_empty:
                if pred(slot):
                    result.append(extract(slot))
        return result 


    def __find_slot(self) -> Optional[ParkingSlot]:
        for slot in self.slots:
            if slot.is_empty:
                return slot

        return None

class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        stack = []
        position_arrival = []
        car_fleets = len(position)
        
        for car_pos, car_vel in zip(position, speed):
            position_arrival.append((car_pos, (target - car_pos) / car_vel))
        position_arrival.sort(reverse=True)
        print(position_arrival)
        for i in range(len(position_arrival)):
            if stack and position_arrival[i][1] <= stack[-1]: car_fleets -= 1
            else: stack.append(position_arrival[i][1])
        
        return car_fleets
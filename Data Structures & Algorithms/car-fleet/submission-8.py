class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        arrival_times = [(pos, (target - pos) / spd) for pos, spd in zip(position, speed)]
        arrival_times.sort(reverse=True)
        n_car_fleets = len(position)
        previous_arr_time = arrival_times[0][1]
        print(arrival_times)
        for i in range(1, len(arrival_times)):
            if arrival_times[i][1] <= previous_arr_time: 
                n_car_fleets -= 1
                continue
            previous_arr_time = arrival_times[i][1]

        return n_car_fleets
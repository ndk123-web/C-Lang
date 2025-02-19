class Process:
    def __init__(self,pid,burst_time,arrival_time):
        self.pid = pid 
        self.burst_time = burst_time
        self.arrival_time = arrival_time
        
def find_Waiting(processes):
    processes.sort(key= lambda x: x.arrival_time)
    curr_time = 0
    waiting_time = [0] * len(processes)
    
    for idx,process in enumerate(processes):
        if idx!=0:
            waiting_time[idx] = curr_time - process.arrival_time
        curr_time += process.burst_time
    
    print("List Of Waiting Time : ",waiting_time)
    print("Average waiting time is: ",sum(waiting_time)/len(processes))
    
    find_turnaround(processes,waiting_time)

def find_turnaround(processses,waiting_time):
    turn_around_time = [0] * len(processes)
    
    for idx,process in enumerate(processes):
        turn_around_time[idx] = process.burst_time + waiting_time[idx]
    
    print("List Of Turnaround Time : ",turn_around_time)
    print("Average Turnaround time is: ",sum(turn_around_time)/len(processes))
    

if __name__ == '__main__':
    processes = [Process(1,6,0),Process(2,8,1),Process(3,7,2),Process(4,3,3)]
    find_Waiting(processes)
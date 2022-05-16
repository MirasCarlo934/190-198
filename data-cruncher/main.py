import csv
import json

# Get filename from user
import json

filename = input("Enter CSV: ")

# Process data
with open(filename) as csv_file:
    csvreader = csv.reader(csv_file, delimiter=';')

    if "NETR" in filename:

        # Create new CSV with better-organized data points
        rowNum = 1
        for row in csvreader:
            print(f"ROW {rowNum}")
            packetIds = row[2]
            packetIdsLen = len(packetIds)
            packetIds = packetIds[1:packetIdsLen-1].split(",")
            packetRtts = row[3]
            packetRttsLen = len(packetRtts)
            packetRtts = packetRtts[1:packetRttsLen-1].split(",")

            print("PACKET IDs")
            for packetId in packetIds:
                print(packetId)

            print("PACKET RTTs")
            for packetRtt in packetRtts:
                print(packetRtt)
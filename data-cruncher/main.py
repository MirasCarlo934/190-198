import csv
import xlsxwriter

# Get details from user
data_dir = input("Enter data directory: ")
date = input("Enter data date: ")
output_filename = input("Enter output CSV filename: ")

# Process data
ids = ["A", "B", "C", "D", "E"]

for id in ids:
    with open(data_dir + "\\" + date + "-node-" + id + "-NETR") as csv_file:

        # Create new CSV with better-organized data points
        csvreader = csv.reader(csv_file, delimiter=';')
        newFilename = "C:\\Users\\user\\OneDrive\\UP\\2S 2021-2022\\CoE 198\\1_data\\processed" + "\\" + data_dir.split("\\")[-1]
        with open(newFilename, mode='w') as newFile:
            csvwriter = csv.writer(newFile, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
            rowNum = 0
            for row in csvreader:
                print(row)
                if rowNum == 0:
                    csvwriter.writerow(["timestamp", "node ID", "sends", "bytes", "packet IDs", "packet RTTs"])
                else:
                    timestamp = row[0]
                    bytes_ = row[1]
                    nodeId = row[2]
                    packetIds = row[3]
                    packetRtts = row[4]
                    sends = row[5]
                    packetIdsLen = len(packetIds)
                    packetIds = packetIds[1:packetIdsLen-1].split(",")
                    packetRttsLen = len(packetRtts)
                    packetRtts = packetRtts[1:packetRttsLen-1].split(",")
                    for i in range(len(packetIds)):
                        newTimestamp = timestamp
                        if i < 10:
                            newTimestamp += ":0" + str(i)
                        else:
                            newTimestamp += ":" + str(i)
                        print(f"{newTimestamp},{nodeId},{sends},{bytes_},{packetIds[i]},{packetRtts[i]}")
                        csvwriter.writerow([newTimestamp, nodeId, sends, bytes_, packetIds[i], packetRtts[i]])
                rowNum = rowNum + 1
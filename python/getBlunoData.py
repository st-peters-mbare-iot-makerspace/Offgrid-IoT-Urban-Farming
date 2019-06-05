from bluepy import btle
import time
import threading


class NotificationDelegate(btle.DefaultDelegate):
   def __init__(self):
      btle.DefaultDelegate.__init__(self)

   def handleNotification(self, cHandle, data):
      decoded_data = data.decode('utf_8','ignore')
      print(decoded_data)  # print received data
      sensorReadings=open("sensorReadings.csv","a")
      sensorReadings.write(decoded_data)
      sensorReadings.close()
      


bt_addrs = ['20:cd:39:87:50:8d','20:cd:39:87:de:6e']
connections = []  # Array holding all connected devices
connection_threads = []  # Array holding all device threads
scanner = btle.Scanner(0)


class ConnectionHandlerThread(threading.Thread):
   def __init__(self, connection_index):
      threading.Thread.__init__(self)
      self.connection_index = connection_index

   def run(self):
      connection = connections[self.connection_index]
      connection.setDelegate(NotificationDelegate())#self.connection_index))
      svc = p.getServiceByUUID("0000dfb0-0000-1000-8000-00805f9b34fb")
      try:
         while True:
            if connection.waitForNotifications(10.0):
               continue
      except btle.BTLEDisconnectError:
            print("Error waiting")
while True:
   devices = scanner.scan(2)
   for d in devices:
      if d.addr in bt_addrs:
        try:
            p = btle.Peripheral(d)
            svc = p.getServiceByUUID("0000dfb0-0000-1000-8000-00805f9b34fb")
            connections.append(p)
            t = ConnectionHandlerThread(len(connections)-1)
            t.start()
            connection_threads.append(t)
            print("created thread")
        except btle.BTLEDisconnectError:
            continue
   


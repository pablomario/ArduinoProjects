import serial

arduino = serial.Serial('/dev/ttyACM0', 9600)

print("Starting!")

while True:
      comando = input('Introduce contrasenya: ') #Input
      #arduino.write(comando.encode()) #Mandar un comando hacia Arduino
      if comando == '1234':
            var_input = 'H'
            arduino.write(var_input.encode())
            print('BIEN')
      else:
            var_input = 'L'
            arduino.write(var_input.encode())
            print('MAL')

arduino.close() #Finalizamos la comunicacion
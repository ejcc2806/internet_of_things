import serial
import time
import os

from supabase import create_client, Client
from getPort import port

url = "https://jhlufmtxeksqgdffkjno.supabase.co"
key = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6ImpobHVmbXR4ZWtzcWdkZmZram5vIiwicm9sZSI6ImFub24iLCJpYXQiOjE3NjE4NTA2MjMsImV4cCI6MjA3NzQyNjYyM30.065VCbQTpxMfxPymIL1n4v9Zb7H1Y8_nK-Q-oRTDpGk"
supabase: Client = create_client(url, key)

arduino_port = port # Don't worry by the port
baud_rate = 9600 # Baudios
ser = serial.Serial(arduino_port, baud_rate, timeout=1)

time.sleep(2)

while True:
    data = ser.readline().decode('utf-8').rstrip()
    #print(data)
    if data:
        try:
            humidity, temperature = data.split(",")
            humidity = float(humidity)
            temperature = float(temperature)

            # --- ENVÍO A SUPABASE ---
            response = supabase.table("data").insert({
                "humidity": humidity,
                "temperature": temperature
            }).execute()

            print("✅ Datos enviados:", humidity, temperature)
        except ValueError:
            print("⚠️ Formato de datos inválido:", data)
        except Exception as e:
            print("❌ Error al enviar a Supabase:", e)
    time.sleep(1)
import socket
from datetime import datetime
import tkinter as tk
from tkinter import messagebox

# Función para enviar los datos al servidor
def enviar_datos():
    nombre, matricula = entry_nombre.get(), entry_matricula.get()
    paquete = f"{nombre},{matricula},{datetime.now().strftime('%Y-%m-%d %H:%M:%S')}"
    
    try:
        # Crear socket y enviar los datos
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
            client_socket.connect(('192.168.181.208', 12345))  # IP de la Raspberry Pi
            client_socket.send(paquete.encode('utf-8'))
        messagebox.showinfo("Éxito", "Datos enviados con éxito")
    except Exception as e:
        messagebox.showerror("Error", f"No se pudo conectar: {e}")

# Configuración de la interfaz gráfica con Tkinter
app = tk.Tk()
app.title("Enviar Datos a Raspberry Pi")
app.geometry("400x300")
app.configure(bg="#ffe6e9")  # Fondo rosa pastel

# Diseño de la interfaz con colores pastel
tk.Label(app, text="Formulario de Envío", font=("Helvetica", 16), bg="#ffe6e9", fg="#ffb6c1").pack(pady=10)  # Texto en rosa claro
tk.Label(app, text="Nombre:", font=("Helvetica", 12), bg="#ffe6e9", fg="#ff69b4").pack(pady=5)  # Texto rosa brillante
entry_nombre = tk.Entry(app, font=("Helvetica", 12), bg="#fff0f5", fg="#ff1493")  # Fondo rosa muy claro con texto rosa fuerte
entry_nombre.pack(pady=5)

tk.Label(app, text="Matrícula:", font=("Helvetica", 12), bg="#ffe6e9", fg="#ff69b4").pack(pady=5)
entry_matricula = tk.Entry(app, font=("Helvetica", 12), bg="#fff0f5", fg="#ff1493")
entry_matricula.pack(pady=5)

# Botón para enviar los datos en colores pastel
tk.Button(app, text="Enviar Datos", font=("Helvetica", 12), bg="#ffb6c1", fg="#fff", command=enviar_datos).pack(pady=10)  # Fondo rosa claro
tk.Button(app, text="Finalizar", font=("Helvetica", 12), bg="#ff69b4", fg="#fff", command=app.destroy).pack(pady=10)  # Fondo rosa fuerte

app.mainloop()

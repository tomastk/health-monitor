# HeartMonitor App

## Integrantes

Gonzalo Dos Santos, Javier Fleitas, Sol Kruzolek, Sebastian Frias, Fabián Frías, Rodrigo Cáceres.

## Descripción del Proyecto

HeartMonitor App es un sistema de monitoreo de salud cardíaca compuesto por un sensor de pulso cardíaco MAX30102 conectado a un microcontrolador ESP32. Los datos son transmitidos a una aplicación móvil desarrollada en AppInventor, utilizando Bluetooth Low Energy (BLE). El sistema permite medir la frecuencia cardíaca y la saturación de oxígeno en sangre (SpO2), almacenar las mediciones y generar recordatorios automáticos.

##Componentes del Sistema

### Hardware:

Sensor MAX30102: Medición de frecuencia cardíaca y SpO2.

Microcontrolador ESP32: Procesamiento y envío de datos por BLE.

Fuente de alimentación: Batería Li-ion o USB.

### Software:

Aplicación móvil en AppInventor: Visualización de mediciones, historial y notificaciones.

Firmware ESP32: Programado en C++ (Arduino IDE o PlatformIO).

### Casos de Uso

Medición de frecuencia cardíaca y SpO2 en tiempo real.

Almacenamiento de mediciones para consulta posterior.

Envío de recordatorios automáticos para realizar mediciones.

### Requerimientos

Conexión BLE entre la app móvil y el ESP32.

Visualización de mediciones en tiempo real.

Almacenamiento seguro de mediciones.

Notificaciones automáticas.

Arquitectura del Sistema

Usuario ↔ Sensor MAX30102 ↔ ESP32 BLE ↔ App Móvil (AppInventor)

Tecnologías Utilizadas

Microcontrolador: ESP32

Sensor: MAX30102

Firmware: C++ (Arduino IDE / PlatformIO)

App Móvil: AppInventor

Comunicación: Bluetooth Low Energy (BLE)

Control de versiones: Git + GitHub

## Mejoras Futuras

Visualización de SpO2 directamente en la app.

Envío de reportes médicos por correo electrónico.

Modo de urgencia con alertas por valores críticos.

Conexión a base de datos en la nube con login de usuario.


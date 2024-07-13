# Juego de Tres en Raya en C++

Este es un juego simple de Tres en Raya implementado en C++. El juego permite a dos jugadores competir entre sí en un tablero de 3x3.

## Incompatibilidades y Requerimientos

El código hace uso de características introducidas en el estándar C++17, como la desestructuración de tuplas utilizando `auto [fila, columna] = Jugada();`. Por lo tanto, es necesario tener un compilador que soporte al menos C++17 para compilar correctamente el código.

### Compiladores y Soporte

Asegúrate de usar un compilador de C++ que sea compatible con C++17 o una versión posterior. Algunos compiladores populares y sus configuraciones:

- **GCC y Clang**: Utiliza la opción `-std=c++17` o superior al compilar. Ejemplo:

  ```bash
  g++ -std=c++17 tictactoe.cpp -o tictactoe

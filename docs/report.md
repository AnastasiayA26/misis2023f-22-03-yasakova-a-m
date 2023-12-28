**28.12.2023**

**Ясакова Анастасия БПМ-22-3**

*Вопрос № 17: Окружение-переменные, особенности использования (Cmake, C++)*

Окружение-переменные – позволяют управлять поведением программ и систем, настраивать среду сборки, управлять путями, интегрироваться с инструментами сборки и адаптироваться к различным средам разработки.

## Использование в CMake:

1) **Управление Путями и Компиляторами в C++:**
   - Указание пути к компилятору и библиотекам C++ (важно при сборке).
   - *Пример (CMake):* `CMAKE_CXX_COMPILER` - определение компилятора, можно дополнительно указать путь к компилятору, если это необходимо.

2) **Конфигурация Среды Сборки в CMake:**
   - Управление параметрами сборки, такими как уровень оптимизации, тип сборки (Debug/Release).
   - *Пример (CMake):* `set(CMAKE_BUILD_TYPE Debug)` - установка уровня оптимизации.

3) **Интеграция с Инструментами Сборки:**
   - Позволяют управлять параметрами сборки и путями в процессе компиляции.
   - *Пример (CMake):*
   ![integration](https://github.com/AnastasiayA26/misis2023f-22-03-yasakova-a-m/blob/main/docs/1.png)
    Интеграция с инструментами сборки, в данном случае с Vcpkg. Toolchain – указывает CMake, как настроить компилятор и другие инструменты сборки с использованием Vcpkg          (управление сторонними зависимостями проекта).

4) **Управление Путями Исполняемых Файлов в CMake:**
    Определение пути вывода исполняемых файлов.
   ![executable_paths](https://github.com/AnastasiayA26/misis2023f-22-03-yasakova-a-m/blob/main/docs/2.png)

5) **Адаптация к Различным Средам:**
   - *Пример (CMake):*
     ![adaptation](https://github.com/AnastasiayA26/misis2023f-22-03-yasakova-a-m/blob/main/docs/3.png)
     Использование переменных окружения для определения путей поиска библиотек в различных средах.
  

6) **Управление Зависимостями с CMake:**
   - Определение путей к сторонним библиотекам и зависимостям.
   - *Пример:*
     ![dependencies](https://github.com/AnastasiayA26/misis2023f-22-03-yasakova-a-m/blob/main/docs/4.png)
      Библиотека `visualization` линкуется с библиотекой `data`.
  

7) **Управление Версиями и Стандартами языка:**
   - В процессе сборки проекта можно использовать переменные окружения для управления версиями компиляторов и стандартами языка.
   - *Пример:*
     `cmake_minimum_required(VERSION 3.23)`
     
     `set(CMAKE_CXX_STANDART 17)`
     
     Установка переменных окружения в процессе сборки.

8) **Установка переменных окружения в процессе сборки:**
   - Позволяет динамически устанавливать переменные окружения, влияя на процесс компиляции и выполнения программы.
   - Может быть полезно для динамической настройки параметров сборки
   - можно обратиться к переменной окружения `MY_VARIABLE` во время компиляции и выполнения проекта.
   - *Пример:* `set(ENV{VAR_NAME} "value")`

## Использование окружения-переменных в C++:

В языке C++, переменные окружения могут быть использованы с помощью стандартной библиотеки `<cstdlib>`.

   <pre>
#include <cstdlib>
#include <iostream>

int main()
{
    if (const char* env_p = std::getenv("PATH"))
        std::cout << "Your PATH is: " << env_p << '\n';
}
</pre>
   
   значения переменной окружения `PATH`.
   - Например, можно установить переменную окружения во время выполнения программы.
     
      <pre>
#include <cstdlib>
#include <iostream>

int main() {
    putenv("MY_VARIABLE=Hello, World!");
    
    const char* value = std::getenv("MY_VARIABLE");

    if (value != nullptr) {
        std::cout << "MY_VARIABLE: " << value << std::endl;
    } else {
        std::cout << "MY_VARIABLE not found." << std::endl;
    }

    return 0;
}
</pre>
   

Такой подход позволяет программе адаптироваться к различным средам выполнения, используя переменные окружения для настройки своего поведения.

## Источники:

1. [cppreference.com - getenv](https://en.cppreference.com/w/cpp/utility/program/getenv)
2. [CMake Tutorial - Debug and Release Builds](https://cmake.org/cmake/help/latest/guide/tutorial/Packaging%20Debug%20and%20Release.html)
3. [CMake Buildsystem Documentation](https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html)
4. [CMake Toolchains Documentation](https://cmake.org/cmake/help/latest/manual/cmake-toolchains.7.html)
5. [CMake set Command Documentation](https://cmake.org/cmake/help/latest/command/set.html)
6. [CMake Environment Variables Documentation](https://cmake.org/cmake/help/latest/manual/cmake-env-variables.7.html)


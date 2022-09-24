# integrator

Программа считает интеграллы функций, написанных на фортране, используя методы интегрирования, написанные на фортране. 

Cборка:

```
mkdir build
```

```
cmake -DCMAKE_BUILD_TYPE=Release ..
```
или

```
cmake -DCMAKE_BUILD_TYPE=Debug ..
```

Исполнение:

```
./integrator [config-file]
```

Пример config-файла:

```
method = simpson
low_lim = 0
high_lim = 1
steps = 100
function = sin
```

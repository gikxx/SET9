# SET9

Этот проект представляет собой сравнительный анализ различных алгоритмов сортировки, включая стандартные и адаптированные версии для работы со строками. Основная цель — оценить их производительность (время выполнения и количество сравнений) на разных типах данных (случайные, обратно отсортированные, почти отсортированные).

## Алгоритмы сортировки
В проекте реализованы и протестированы следующие алгоритмы:

QuickSort (стандартная версия для чисел).

MergeSort (стандартная версия для чисел).

StringQuickSort (адаптированная версия QuickSort для строк).

StringMergeSort (адаптированная версия MergeSort для строк).

MSDRadixSort (поразрядная сортировка без использования QuickSort).

MSDRadixSortWithQS (гибридный алгоритм: MSD Radix Sort + QuickSort).

В репозитории представлены итоговые данные по тетированию сортировок и классы StringGenerator, StringSortTester

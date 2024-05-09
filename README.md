# Инструкция по установке и работе с библиотекой FFMPEG на Linux
 FFMPEG предназначена для конвертирования видео и аудио файлов.
 Личный опыт использование пробоводился на Linux-xubuntu с установленым Cmake.
 С ЧЕГО НАЧАТЬ?
Шаг №1. Устанавливаем Cmake на Linux
Для этого вам надо либо собрать из исходников либо использовать менеджер пакетов
командой 
sudo apt install cmake
Шаг №2. Устанавливаем FFMPEG на Linux
Для этого вам понадобится собрать из изходников либо воспользоваться менеджером пакетов 
sudo apt install ffmpeg
sudo apt-get install libavfilter-dev
Шаг №3. Собрать готовый проект(Пример использования ffmpeg)
mkdir build
cd build
cmake ..
make
Шаг №4. Запуск проета
./decode_encode
Краткий вывод возможностей FFMPEG
количество потоков: 2
AUDIO codec: aac
VIDEO codec: h264
Длительность общая: 110 s
FPS : 59.9401
//////////////////////////////////////////////////////////////////////////////////////////
//---------------------------ПОДКЛЮЧЕНИЕ ЗАГОЛОВОЧНЫХ ФАЙЛОВ----------------------------//
//////////////////////////////////////////////////////////////////////////////////////////
#include "mp4parser.h"
#include "streamreader.h"

//////////////////////////////////////////////////////////////////////////////////////////
//---------------------------ОСНОВНАЯ ФУНКЦИЯ MAIN--------------------------------------//
//////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    //StreamReader reader("//pc01/public_share/file_03_05_2015_23-27-38.mp4");
    StreamReader reader("D:/file_03_05_2015_23-27-381.mp4");                             //задание пути к MP4 файлу
    if (reader.openStream())                                                            //если MP4 файл успешно открылся
    {
        MP4Parser parser;                                                               //создание объекта MP4Parser
        parser.parse(reader);                                                           //парсинг всех атомов MP4 файла
        //parser.prepareData(450,650);                                                    //подготовка данных MP4 файла к вырезанию указанного промежутка времени
        parser.prepareData(15,45);
        StreamWriter writer("D:/newfile1.mp4");                                          //задание пути к новому обрезанному MP4 файлу
        if(writer.openStream()){                                                        //если новый MP4 файл открылся успешно на вывод
            parser.writeOnlyVideo(reader,writer);                                       //идет запись в новый файл MP4 всех необходимых данных для создания обрезанного MP4
        }
    }
    system("pause");
    return 0;                                                               //завершение работы программы
}

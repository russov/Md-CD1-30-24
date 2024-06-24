// #include "mainwindow.h"

// #include <QApplication>

// int main(int argc, char *argv[])
// {
//    QApplication a(argc, argv);
//    MainWindow w;


//    return a.exec();
// }




// #include <QTextStream> // подключаем необходимый заголовочный файл
// #include <QString>
// #include <iostream>

// int main() {

//     QTextStream out(stdout);

//     // Создаем строку типа QString
//     QString a{"love"};

//     // Добавляем текст в конец строки
//     a.append(" chess");

//     // Добавляем текст в начало строки
//     a.prepend("I ");

//     // Выводим строку
//     std::cout << a.toStdString() << std::endl;

//     // Выводим количество символов строки
//     out << "The a string has " << a.size() << " characters" << Qt::endl;

//     // Выводим всю строку в верхнем регистре
//     out << a.toUpper() << Qt::endl;

//     // Выводим всю строку в нижнем регистре
//     out << a.toLower() << Qt::endl;

//     return 0;
// }





//инициализация строки
// #include <QTextStream>
// #include <QString>

// int main() {

//     QTextStream out(stdout);

//     // Инициализация №1: Традиционный вариант
//     QString str1 = "The night train";
//     out << str1 << Qt::endl;

//     // Инициализация №2: Объектный способ
//     QString str2("A yellow rose");
//     out << str2 << Qt::endl;

//     QString str21{"A yellow rose"};
//     out << str21 << Qt::endl;

//     // Инициализация №3
//     std::string s1 = "A blue sky";
//     QString str3 = s1.c_str();
//     out << str3 << Qt::endl;

//     // Инициализация №4
//     std::string s2 = "A thick fog";
//     QString str4 = QString::fromLatin1(s2.data(), s2.size());
//     out << str4 << Qt::endl;

//     // Инициализация №5
//     char s3[] = "A deep forest";
//     QString str5(s3);
//     out << str5 << Qt::endl;

//     return 0;
// }





// доступ по индексу
// #include <QTextStream>
// #include <QString>

// int main() {

//     QTextStream out(stdout);

//     // Исходная строка
//     QString a = "Eagle";

//     // Выводим первый символ строки
//     out << a[0] << Qt::endl;

//     // Выводим пятый символ строки
//     out << a[4] << Qt::endl;

//     // Выводим первый символ строки с помощью метода at()
//     out << a.at(0) << Qt::endl;

//     return 0;
// }







//длина строки
// #include <QTextStream>
// #include <QString>
// int main() {

//     QTextStream out(stdout);

//     // Обычная строка
//     QString s1 = "Eagle";

//     // Здесь у нас символ новой строки
//     QString s2 = "Eagle\n";

//     // Здесь у нас пробел в конце строки
//     QString s3 = "Eagle ";

//     // А это вообще кириллица
//     QString s4 = "орел";

//     out << s1.length() << Qt::endl;
//     out << s2.length() << Qt::endl;
//     out << s3.length() << Qt::endl;
//     out << s4.length() << Qt::endl;
//     out << s4.size()   << Qt::endl;
//     //out << s4.count()  << Qt::endl;

//     return 0;
// }






//построение строк
// #include <QTextStream>
// #include <QString>

// int main() {

//     QTextStream out(stdout);

//     // Используем маркер %1 для вставки значения
//     QString s1 = "There are %2 %1 white roses";

//     // Наш маркер будет заменяться этим целочисленным значением
//     int n = 12;

//     // Выполняем операцию вставки значения
//     out << s1.arg(n).arg(5) << Qt::endl;

//     // Используем маркер %1 для вставки значения
//     QString s2 = "The tree is %1 m high";

//     // Наш маркер будет заменяться этим значением типа с плавающей точкой
//     double h = 5.65;

//     // Выполняем операцию вставки значения
//     out << s2.arg(h) << Qt::endl;

//     // Используем 2 маркера для вставки 2 значений
//     QString s3 = "We have %1 lemons and %2 oranges";

//     // Наши маркеры будут заменяться следующими значениями
//     int ln = 12;
//     int on = 4;

//     // Выполняем операцию вставки
//     out << s3.arg(ln).arg(on) << Qt::endl;

//     return 0;
// }





//подстроки

// #include <QTextStream>
// #include <QString>

// int main() {

//     QTextStream out(stdout);

//     // Исходная строка
//     QString str = "The night train";

//     // Возвращаем подстроку длиной 5 символов, начиная с правого края строки str
//     out << str.right(5) << Qt::endl;

//     // Возвращаем подстроку длиной 9 символов, начиная с левого края строки str
//     out << str.left(9) << Qt::endl;

//     // Возвращаем подстроку длиной 5 символов, начиная с 4-ого символа строки str
//     out << str.mid(4, 5) << Qt::endl;

//     return 0;
// }






//циклы и строки
// #include <QTextStream>
// #include <QString>

// int main() {

//     QTextStream out(stdout);

//     QString str = "There are many stars.";

//     // Способ №1
//     foreach (QChar qc, str) {
//         out << qc << " ";
//     }

//     out << Qt::endl;

//     // Способ №2
//     for (QChar *it=str.begin(); it!=str.end(); ++it) {
//         out << *it << " " ;
//     }

//     out << Qt::endl;

//     // Способ №3
//     for (int i = 0; i < str.size(); ++i) {
//         out << str.at(i) << " ";
//     }

//     out << Qt::endl;

//     return 0;
// }






//сравнение строк
// #include <QTextStream>
// #include <QString>

// // Добавляем для лучшей читабельности кода
// const int STR_EQUAL=0;

// using namespace Qt;

// int main() {

//     QTextStream out(stdout);

//     // Будем сравнивать следующие 3 строки
//     QString a = "Rain";
//     QString b = "rain";
//     QString c = "rain\n";

//     // Первое сравнение - отличие сразу же в первом символе
//     if (QString::compare(a, b) == STR_EQUAL) {
//         out << "a, b are equal" << endl;
//     } else {
//         out << "a, b are not equal" << endl;
//     }

//     out << "In case insensitive comparison:" << endl;

//     // С помощью флага Qt::CaseInsensitive отключаем чувствительность к регистру
//     if (QString::compare(a, b, Qt::CaseInsensitive) == STR_EQUAL) {
//         out << "a, b are equal" << endl; // и получаем равные строки
//     } else {
//         out << "a, b are not equal" << endl;
//     }

//     if (QString::compare(b, c) == STR_EQUAL) {
//         out << "b, c are equal" << endl;
//     } else {
//         out << "b, c are not equal" << endl;
//     }

//     // Удаляем символ новой строки в строке c
//     c.chop(1);

//     out << "After removing the new line character" << endl;

//     if (QString::compare(b, c) == STR_EQUAL) {
//         out << "b, c are equal" << endl; // теперь наши строки равны
//     } else {
//         out << "b, c are not equal" << endl;
//     }

//     return 0;
// }




// #include <QTextStream>
// #include <QString>

// int main() {

//     QTextStream out(stdout);

//     // Наши строки
//     QString s1 = "12";
//     QString s2 = "15";
//     QString s3, s4;

//     // С помощью метода toInt() конвертируем строки в целочисленный тип данных, а затем складываем получившиеся числа
//     out << s1.toInt() + s2.toInt() << Qt::endl;

//     int n1 = 30;
//     int n2 = 40;

//     // С помощью метода setNum() выполняем конвертацию из целочисленного типа данных в QString, а затем соединяем уже строки
//     out << s3.setNum(n1) + s4.setNum(n2) << Qt::endl;

//     return 0;
// }







// #include <QTextStream>
// #include <QString>

// int main() {

//     QTextStream out(stdout);

//     // Исходная строка
//     QString str = "Lovely";

//     // С помощью метода append() добавляем новую строку в конец исходной строки
//     str.append(" season");
//     out << str << Qt::endl;

//     // С помощью метода remove() удаляем 3 символа, начиная с позиции №10 исходной строки
//     str.remove(10, 3);
//     out << str << Qt::endl;

//     // С помощью метода replace() заменяем 3 символа, начиная с позиции №7 исходной строки
//     str.replace(7, 3, "girl");
//     out << str << Qt::endl;

//     // Очищаем строку
//     str.clear();

//     if (str.isEmpty()) {
//         out << "The string is empty" << Qt::endl;
//     }

//     return 0;
// }





//QVector
// #include <QVector>
// #include <QTextStream>

// int main(void) {

//     QTextStream out(stdout);

//     // Создаем вектор, содержащий целочисленные значения
//     QVector<int> vals = {1, 2, 3, 4, 5};

//     // С помощью метода size() возвращаем размер вектора (количество элементов, содержащихся в нем)
//     out << "The size of the vector is: " << vals.size() << Qt::endl;

//     out << "The first item is: " << vals.first() << Qt::endl; // получаем первый элемент вектора
//     out << "The last item is: " << vals.last() << Qt::endl; // получаем последний элемент вектора

//     vals.append(6); // вставляем новый элемент в конец вектора
//     vals.prepend(0); // вставляем новый элемент в начало вектора

//     out << "Elements: ";

//     // Перебираем элементы вектора и выводим их на экран
//     for (int val : vals) {
//         out << val << " ";
//     }

//     out << Qt::endl;

//     return 0;
// }




//QList
// #include <QTextStream>
// #include <QList>
// #include <algorithm>

// int main(void) {

//     QTextStream out(stdout);

//     // Создаем контейнер QList, в котором будем хранить имена писателей
//     QList<QString> authors = {"Balzac", "Tolstoy",
//                               "Gulbranssen", "London"};

//     // Перебираем каждый элемент массива и выводим на экран
//     for (int i=0; i < authors.size(); ++i) {

//         out << authors.at(i) << Qt::endl; // метод at() возвращает элемент с указанным индексом
//     }

//     // С помощью оператора << вставляем в список 2 новых элемента
//     authors << "Galsworthy" << "Sienkiewicz";

//     out << "***********************" << Qt::endl;

//     // С помощью метода sort() сортируем список в порядке возрастания
//     std::sort(authors.begin(), authors.end());

//     // Выводим на экран отсортированный список
//     out << "Sorted:" << Qt::endl;
//     foreach (const QString &author, authors) {

//         out << author << Qt::endl;
//     }
// }



//QSet
// #include <QSet>
// #include <QList>
// #include <QTextStream>
// #include <algorithm>

// int main(void) {

//     QTextStream out(stdout);

//     // Создаем 2 набора цветов
//     QSet<QString> cols1 = {"yellow", "red", "blue"};
//     QSet<QString> cols2 = {"blue", "pink", "orange"};

//     // С помощью метода size() возвращаем размер набора
//     out << "There are " << cols1.size() << " values in the set" << Qt::endl;

//     // С помощью метода insert() вставляем новый элемент
//     cols1.insert("brown");

//     out << "There are " << cols1.size() << " values in the set" << Qt::endl;

//     // Метод unite() выполняет объединение двух наборов
//     cols1.unite(cols2);

//     out << "There are " << cols1.size() << " values in the set" << Qt::endl;

//     // Перебираем все элементы набора cols1 и выводим их на экран
//     for (const QString& val : cols1) {
//         out << val <<Qt::endl;
//     }

//     // Создаем отдельный список из набора элементов cols1 для их сортировки
//     QList<QString> lcols = cols1.values(); // метод values() возвращает новый QList, содержащий элементы набора
//     lcols.sort();

//     //std::sort(lcols.begin(), lcols.end());

//     out << "*********************" << Qt::endl;
//     out << "Sorted:" << Qt::endl;

//     for (const QString& val : lcols) {
//         out << val << Qt::endl;
//     }

//     return 0;
// }






//QMap
// #include <QTextStream>
// #include <QMap>

// int main(void) {

//     QTextStream out(stdout);

//     // Создаем QMap, содержащий 2 пары элементов
//     QMap<QString, int> items = { {"coins", 5}, {"books", 3} };

//     // С помощью метода insert() добавляем новую пару значений
//     items.insert("bottles", 7);

//     // Получаем все значения словаря и выводим их на экран
//     QList<int> values = items.values(); // метод values() возвращает список значений словаря
//     out << "Values:" << Qt::endl;
//     for (int val : values) {
//         out << val << Qt::endl;
//     }

//     // Аналогично выводим все ключи словаря
//     QList<QString> keys = items.keys(); // метод keys() возвращает список, содержащий все ключи в словаре
//     out << "Keys:" << Qt::endl;
//     for (const QString& key : keys) {
//         out << key << Qt::endl;
//     }

//     // Создаем итератор для QMap в Java-стиле
//     QMapIterator<QString, int> it(items); // этот итератор может использоваться для итерации по элементам QMap

//     out << "Pairs:" << Qt::endl;

//     // С помощью итератора перебираем все элементы QMap
//     while (it.hasNext()) {
//         it.next();
//         out << it.key() << ": " << it.value() << Qt::endl; // метод key() возвращает текущий ключ, а метод value() возвращает текущее значение
//     }
// }






//размер файла
// #include <QTextStream>
// #include <QFileInfo>

// int main(int argc, char *argv[]) {

//     QTextStream out(stdout);

//     if (argc != 2) {

//         qWarning("Usage: file_size file");
//         return 1;
//     }

//     // Имя файла передается в качестве аргумента в нашу программу
//     QString filename = argv[1];

//     // Проверяем существование файла
//     if (!QFile(filename).exists()) {
//         qWarning("The file does not exist"); // если файл не найден, то выводим предупреждение и завершаем работу программы
//         return 1;
//     }

//     // Создаем объект
//     QFileInfo fileinfo(filename);

//     // Определяем размер файла с помощью метода size()
//     qint64 size = fileinfo.size(); // qint64 - это тип данных, который гарантированно будет 64-битным на всех платформах, поддерживаемых Qt

//     // Выводим результат
//     QString str = "The size is: %1 bytes";
//     out << str.arg(size) << Qt::endl;
// }






//чтение файла
// #include <QTextStream>
// #include <QFile>

// int main() {

//     QTextStream out(stdout);

//     // Создаем объект
//     QFile file("..\\..\\test.txt");

//     // С помощью метода open() открываем файл в режиме чтения
//     if (!file.open(QIODevice::ReadOnly)) {
//         qWarning("Cannot open file for reading"); // если файл не найден, то выводим предупреждение и завершаем выполнение программы
//         return 1;
//     }

//     // Создаем входящий поток, из которого будут считываться данные, и связываем его с нашим файлом
//     QTextStream in(&file);

//     // Считываем файл строка за строкой
//     while (!in.atEnd()) { // метод atEnd() возвращает true, если в потоке больше нет данных для чтения
//         QString line = in.readLine(); // метод readLine() считывает одну строку из потока
//         out << line << Qt::endl;
//     }

//     // Закрываем файл
//     file.close();
// }





//запись в файл
// #include <QTextStream>
// #include <QFile>

// int main() {

//     QTextStream out(stdout);

//     // Создаем объект класса QFile и связываем его с указанным именем файла
//     QString filename = "..\\..\\distros.txt";
//     QFile file(filename);

//     // Открываем файл в режиме "Только для записи"
//     if (file.open(QIODevice::WriteOnly)) {
//         QTextStream out(&file); // поток записываемых данных направляем в файл

//         // Для записи данных в файл используем оператор <<
//         out << "Xubuntu" << Qt::endl;
//         out << "Arch" << Qt::endl;
//         out << "Debian" << Qt::endl;
//         out << "Redhat" << Qt::endl;
//         out << "Slackware" << Qt::endl;

//     } else {

//         qWarning("Could not open file");
//     }

//     // Закрываем файл
//     file.close();
// }





// копирование файла
// #include <QTextStream>
// #include <QFile>
// #include <conio.h>

// int main(int argc, char *argv[]) {

//     // Программа принимает 2 параметра
//     if (argc != 2) {
//         qWarning("Usage: copyfile source destination"); // если параметров нет, то выводится предупреждение
//         return 1;
//     }

//     // Из аргументов командной строки программы мы получаем имя исходного файла
//     QString source = argv[1];

//     // Проверяем наличие исходного файла
//     if (!QFile(source).exists()) {
//         qWarning("The source file does not exist"); // если файл не найден, то выводим предупреждение и завершаем выполнение программы
//         return 1;
//     }

//     // Получаем имя файла назначения
//     QString destin("..\\..\\copy.txt");

//     // Копируем исходный файл
//     QFile::copy(source, destin); // первый параметр - это имя исходного файла, а второй - имя конечного файла
// }







//работа с каталогом
// #include <QTextStream>
// #include <QDir>
// #include <conio.h>

// int main() {

//     QTextStream out(stdout);

//     QDir dir;

//     // Метод mkdir() создает каталог, при этом возвращая true, если каталог был успешно создан
//     if (dir.mkdir("mydir")) {
//         out << "mydir successfully created" << Qt::endl;
//     }

//     dir.mkdir("mydir2");

//     // Метод exists() проверяет наличие каталога
//     if (dir.exists("mydir2")) {
//         dir.rename("mydir2", "newdir"); // метод rename() переименовывает каталог
//     }

//     // Создаем новый каталог и все необходимые родительские каталоги
//     dir.mkpath("temp/newdir");
// }





//пути к файлам
// #include <QTextStream>
// #include <QFileInfo>
// #include <conio.h>

// int main(int argc, char *argv[]) {

//     QTextStream out(stdout);

//     if (argc != 2) {
//         out << "Usage: file_times file" << Qt::endl;
//         return 1;
//     }

//     QString filename = argv[1];

//     // Определяем путь к файлу
//     QFileInfo fileinfo(filename);

//     QString absPath = fileinfo.absoluteFilePath(); // возвращаем абсолютный путь, включающий имя файла
//     QString baseName = fileinfo.baseName(); // возвращаем базовое имя: имя файла без пути
//     QString compBaseName = fileinfo.completeBaseName(); // возвращаем полное базовое имя: все символы в имени файла до последней точки (но не включая её)
//     QString fileName = fileinfo.fileName(); // возвращаем имя файла, которое является базовым именем + расширение
//     QString suffix = fileinfo.suffix(); // возвращаем расширение файла, которое состоит из всех символов в базовом имени файла + расширение после последнего символа точки (но не включая её)
//     QString compSuffix = fileinfo.completeSuffix(); // возвращаем расширение файла, которое состоит из всех символов в базовом имени файла + расширение после первого символа точки (но не включая её)

//     out << "Absolute file path: " << absPath << Qt::endl;
//     out << "Base name: " << baseName << Qt::endl;
//     out << "Complete base name: " << compBaseName << Qt::endl;
//     out << "File name: " << fileName << Qt::endl;
//     out << "Suffix: " << suffix << Qt::endl;
//     out << "Whole suffix: " << compSuffix << Qt::endl;
// }






//содержимое каталога
// #include <QTextStream>
// #include <QFileInfo>
// #include <QDir>
// #include <conio.h>

// int main() {

//     QTextStream out(stdout);

//     QString directory = "..\\..\\";

//     // Создаем объект класса QDir с заданным именем каталога
//     QDir dir(directory);

//     if (!dir.exists()) {
//         qWarning("The directory does not exist");
//         return 1;
//     }

//     // Метод setFilter() определяет тип файлов, которые должны быть возвращены методом entryInfoList()
//     dir.setFilter(QDir::Files | QDir::AllDirs);

//     // Метод setSorting() задает порядок сортировки, используемый методом entryInfoList()
//     dir.setSorting(QDir::Size | QDir::Reversed);

//     // Метод entryInfoList() возвращает список объектов QFileInfo для всех файлов и папок в каталоге, отфильтрованных и упорядоченных соответствующими методами
//     QFileInfoList list = dir.entryInfoList();

//     int max_size = 0;

//     // Проходимся по списку и определяем максимальный размер имени файла
//     foreach (QFileInfo finfo, list) {

//         QString name = finfo.fileName();
//         int size = name.size();

//         if (size > max_size) {
//             max_size = size;
//         }
//     }

//     // Добавляем дополнительные два пробела к длине столбца
//     int len = max_size + 2;

//     // Выводим имена столбцов
//     out << QString("Filename").leftJustified(len).append("Bytes") << Qt::endl; // метод leftJustified() возвращает строку заданного размера, выравненную по левому краю и дополненную символом заполнения (по умолчанию пробел) справа

//     // Просматриваем список файлов и выводим их названия и размеры. Первый столбец выравнивается по левому краю и заполняется пробелами по мере необходимости, затем добавляется второй столбец
//     for (int i = 0; i < list.size(); ++i) {
//         QFileInfo fileInfo = list.at(i);
//         QString str = fileInfo.fileName().leftJustified(len);
//         str.append(QString("%1").arg(fileInfo.size()));
//         out << str << Qt::endl;
//     }

//     return 0;
// }




//signal/slot
// #include <QApplication>
// #include "click.h"

// int main(int argc, char *argv[]) {

//     QApplication app(argc, argv);

//     Click window;

//     window.resize(250, 150);
//     window.setWindowTitle("Click");
//     window.show();

//     return app.exec();
// }



//move
// #include <QApplication>
// #include "move.h"

// int main(int argc, char *argv[]) {

//     QApplication app(argc, argv);

//     Move window;

//     window.resize(250, 150);
//     window.setWindowTitle("Move");
//     window.show();

//     return app.exec();
// }




//timer
// #include <QApplication>
// #include "timer.h"

// int main(int argc, char *argv[]) {

//     QApplication app(argc, argv);

//     Timer window;

//     window.resize(250, 150);
//     window.setWindowTitle("Timer");
//     window.show();

//     return app.exec();
// }






//signal/slot disconnect
// #include <QApplication>
// #include "disconnect.h"

// int main(int argc, char *argv[]) {

//     QApplication app(argc, argv);

//     Disconnect window;

//     window.resize(250, 150);
//     window.setWindowTitle("Disconnect");
//     window.show();

//     return app.exec();
// }





//----------------------------------------------------------------------------------------
//GUI
// #include <QApplication>
// #include <QWidget>

// int main(int argc, char *argv[]) {

//     // Каждое Qt5-приложение (за исключением консольных) должно включать следующую строку
//     QApplication app(argc, argv);

//     // Главный виджет, который представляет окно нашей программы
//     QWidget window;

//     window.resize(250, 150); // изменяем размер виджета в пикселях
//     window.setWindowTitle("Simple example"); // устанавливаем заголовок для главного окна
//     window.show(); // выводим виджет на экран

//     // С помощью метода exec() запускаем основной цикл нашей программы
//     return app.exec();
// }






//курсор
// #include <QApplication>
// #include <QWidget>
// #include <QFrame>
// #include <QGridLayout>

// class Cursors : public QWidget {

// public:
//     Cursors(QWidget *parent = 0);
// };

// Cursors::Cursors(QWidget *parent)
//     : QWidget(parent) {

//     QFrame *frame1 = new QFrame(this); // создаем виджет
//     frame1->setFrameStyle(QFrame::Box); // устанавливаем рамки фрейма
//     frame1->setCursor(Qt::SizeAllCursor); // задаем тип курсора SizeAllCursor для фрейма

//     QFrame *frame2 = new QFrame(this); // создаем виджет
//     frame2->setFrameStyle(QFrame::Box); // устанавливаем рамки фрейма
//     frame2->setCursor(Qt::WaitCursor); // задаем тип курсора WaitCursor для фрейма

//     QFrame *frame3 = new QFrame(this); // создаем виджет
//     frame3->setFrameStyle(QFrame::Box); // устанавливаем рамки фрейма
//     frame3->setCursor(Qt::PointingHandCursor); // задаем тип курсора PointingHandCursor для фрейма

//     // Группируем все фреймы в одну строку
//     QGridLayout *grid = new QGridLayout(this);
//     grid->addWidget(frame1, 0, 0);
//     grid->addWidget(frame2, 0, 1);
//     grid->addWidget(frame3, 0, 2);

//     setLayout(grid);
// }

// int main(int argc, char *argv[]) {

//     QApplication app(argc, argv);

//     Cursors window;

//     window.resize(350, 150);
//     window.setWindowTitle("Cursors");
//     window.show();

//     return app.exec();
// }





//QMainform
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}

#include <QCoreApplication>
#include <mutex>
#include <thread>
#include "linkedlist.h"
#include <sstream>
#include <chrono>
#include <ctime>
#include<stdlib.h>
#include<time.h>

mutex vectLock;

LinkedList* lista= new LinkedList();

void process(int id){
    srand(time(NULL));

        auto nowTime = std::chrono:: system_clock::now();
        std::time_t sleepTime = std::chrono::system_clock::to_time_t(nowTime);
        qDebug() << "Thread: " << id << "sleep Time: " << std::ctime(&sleepTime);// << "\n";

        int i=0,num=0;
        switch (id) {
        case 1:
            qDebug()<<"ELIMINACION";
            while (i<10) {
                num=1+rand()%10;
                vectLock.lock();
                lista->deletee(num);
                vectLock.unlock();
                i++;
            }
            break;
        case 2:
            qDebug()<<"INSERCION";
            while (i<10) {
                num=1+rand()%10;
                vectLock.lock();
                lista->insert(num);
                vectLock.unlock();
                i++;
            }
            break;
        case 3:
            qDebug()<<"BUSQUEDA";
            while (i<10) {
                num=1+rand()%10;
                vectLock.lock();
                lista->search(num);
                vectLock.unlock();
                i++;
            }
            break;

    }
        std::this_thread::sleep_for(std::chrono::seconds(1));
        nowTime = std::chrono:: system_clock:: now();
        sleepTime = std::chrono::system_clock::to_time_t(nowTime);
        qDebug() << "Thread " << id << " Awake Time : " << std::ctime(&sleepTime) << "\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    thread th1(process,2);
        th1.join();
        thread th2(process,1);
        th2.join();
        thread th3(process,3);
        th3.join();
        thread th4(process,4);
        th4.join();

        delete lista;
        return a.exec();
}

#include <QApplication>
#include <QPushButton>
#include "spdlog/spdlog.h"
#include "../logger/logger.h"


int main(int argc, char *argv[]) {
    LOG_INFO("Hello");
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}

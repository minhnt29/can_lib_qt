#include <QApplication>
#include <QPushButton>
#include "spdlog/spdlog.h"

int main(int argc, char *argv[]) {
    spdlog::info("Welcome to spdlog!");
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}

//
// Created by minh on 7/18/2024.
// DBC Handle is a singleton object that manage dbc, dbc changing or
// all information about message, signal
//

#ifndef CAN_LIB_DBC_HANDLE_H
#define CAN_LIB_DBC_HANDLE_H

#include <QCanDbcFileParser>
#include <QCanMessageDescription>

#define DBC_HANDLE DbcHandle::instance()

class DbcHandle{
public:
    static DbcHandle& instance() {
        //Meyer Singleton for DBC Handle
        static DbcHandle dbc_handle;
        return  dbc_handle;
    }

    QCanMessageDescription getMessageInstance(QString message_name);
    QCanMessageDescription getMessageInstance(uint32_t message_id);


private:
    std::unique_ptr<QCanDbcFileParser> *dbc_parser = nullptr;
    QString dbc_path = QString();
    QList<QCanMessageDescription> list_can_des = {};
};
#endif //CAN_LIB_DBC_HANDLE_H

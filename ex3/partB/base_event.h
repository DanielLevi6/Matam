#ifndef BASE_EVENT_H
#define BASE_EVENT_H

#include "../partA/date_wrap.h"
#include "../partA/exceptions.h"
#include "linked_list.h"
#include <string.h>
#include <iostream>
#include <cstdbool>

namespace mtm {

    class BaseEvent {
        DateWrap date;
        std::string name;

    protected:
        LinkedList<int> members_list;

    public:
        BaseEvent(const DateWrap& date, const std::string name = "");
        BaseEvent(const BaseEvent& event);
        virtual ~BaseEvent() = default;
        BaseEvent& operator=(const BaseEvent& event) = default;
        virtual void registerParticipant(int student_id)=0;
        void unregisterParticipant(int student_id);
        std::ostream& printShort(ostream& os);
        std::ostream& printLong(ostream& os);
        virtual BaseEvent* clone() const =0;
        const DateWrap getDate() const;
        const std::string getName() const;
        bool operator>(const BaseEvent& event) const;
        bool operator<(const BaseEvent& event) const;
        bool operator==(const BaseEvent& event) const;
    };

    bool compareEvents(const BaseEvent* event1,const BaseEvent* event2);
}

#endif /* BASE_EVENT_H */
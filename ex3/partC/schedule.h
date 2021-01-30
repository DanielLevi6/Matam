#ifndef SCHEDULE_H_
#define SCHEDULE_H_


#include <iostream>
#include <vector>
#include <string>
#include "../partB/event_container.h"
#include "../partB/linked_list.h"
#include "../partA/exceptions.h"
#include "../partB/ptr_vector.h"

using std::cout;
using std::string;
using std::endl;
using std::vector;

namespace mtm{
    class Schedule{
        vector<BaseEvent*> events_list;
        PtrVector pointers_vector;
    public:
        Schedule():pointers_vector(){}
        ~Schedule(){
            for(int i=0;i<pointers_vector.counter;i++){
                delete pointers_vector.events[i];
            }
        }
        void addEvents(const EventContainer& container);
        bool checkIfExist(const EventContainer& container);
        void registerToEvent(const DateWrap& date,string name, int student_id);
        void unregisterFromEvent(const DateWrap& date,string name, int student_id);
        void printAllEvents() const;
        void printMonthEvents(int month,int year) const;
        void printEventDetails(const DateWrap& date,string name) const;
        void sortVector();
        void swapVector(int index1,int index2);

        template <typename Predicate>
        void printSomeEvents(Predicate pred,bool verbose) const{
            for(int i=0;i<events_list.size();i++) {
                if(pred(*events_list[i])){
                    if(verbose){
                        (*events_list[i]).printLong(cout) << endl;
                    }else{
                        (*events_list[i]).printShort(cout) << endl;
                    }
                }
            }
        }
    };
}
#endif


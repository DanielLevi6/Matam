#ifndef PTR_VECTOR_H
#define PTR_VECTOR_H

#include "base_event.h"

const int START=1;

namespace mtm{
    /**
     * A vector which stores all the events we allocates and frees them in the end
     */
    class PtrVector{
    public:
        BaseEvent** events;
        int length;
        int counter;

        PtrVector(int length=START):length(length),counter(0){
            events=new BaseEvent*[length];
        }

        ~PtrVector(){
            delete[] events;
        }

        void add(BaseEvent* new_event){
            if(counter==length){
                BaseEvent** new_events_array=new BaseEvent*[++length];
                
                for(int i=0;i<counter;i++){
                    new_events_array[i]=events[i];
                }

                delete[] events;
                events=new_events_array;
            }
            events[counter++]=new_event;
        }
    };
}

#endif
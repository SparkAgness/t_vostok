#include <iostream>
#include <memory>
#include "change_arr_.h"

using namespace changeable_array;

void Array::PushBack(int x, int y)
{   
    
    if ((0 == last_.GetCoord_(true)) && (0 == last_.GetCoord_(false))) {
        last_.SetCoord(x, y);     
        #ifdef DEBUG_PUSHBACK
            std::cout << "---PUSHBACK---" << "\n";
            std::cout << "Creating last - x is: " << last_.GetCoord_(true) << " y is: " << last_.GetCoord_(false) << "\n";
        #endif  
    } else { 
        ArrNode tmp;
        std::shared_ptr<ArrNode> p_tmp {std::make_shared<ArrNode> (tmp)};
        std::shared_ptr<ArrNode> last {std::make_shared<ArrNode> (last_)};
        std::shared_ptr<ArrNode> first{std::make_shared<ArrNode>(first_)};
        //first->SetForwardLink(last);
        //last->SetBackLink(first);
        std::shared_ptr<ArrNode> middle = last->GetLink(false);
        #ifdef DEBUG_PUSHBACK
            std::cout << "Middle is - x: " << middle->GetCoord_(true) << " y: " << middle->GetCoord_(false) << "\n";
            std::cout << "Last from first is - x: " << (first->GetLink())->GetCoord_(true) << " y: " << (first->GetLink())->GetCoord_(false) << "\n";
            std::cout << "Last is - x: " << last->GetCoord_(true) << " y: " << last->GetCoord_(false) << "\n";
        #endif
        middle->SetForwardLink(p_tmp);
        last->SetBackLink(p_tmp);
        p_tmp->SetBackLink(middle);
        p_tmp->SetForwardLink(last);
        p_tmp->SetCoord(last->GetCoord_(true), last->GetCoord_(false));
        last->SetCoord(x, y);
        #ifdef DEBUG_PUSHBACK            
            std::cout << "FIRST FROM TMP: " << (p_tmp->GetLink(false))->GetCoord_(true) << " " << (p_tmp->GetLink(false))->GetCoord_(false) << std::endl;
        #endif
        #ifdef DEBUG_PUSHBACK
            std::cout << "AFTER LINKING TMP IS: " << p_tmp->GetCoord_(true) << " " << p_tmp->GetCoord_(false) << std::endl;
            std::cout << "AFTER LINKING LAST FROM TMP: " << (p_tmp->GetLink())->GetCoord_(true) << " " << (p_tmp->GetLink())->GetCoord_(false) << std::endl;
            std::cout << "AFTER LINKING FIRST FROM TMP: " << (p_tmp->GetLink(false))->GetCoord_(true) << " " << (p_tmp->GetLink(false))->GetCoord_(false) << std::endl;
            std::cout << "AFTER LINKING NEXT BY 1ST IS: " << (first->GetLink())->GetCoord_(true) << " " << (first->GetLink())->GetCoord_(false) << std::endl;
        #endif
        #ifdef DEBUG_PUSHBACK
            std::cout << "AFTER INIT STRAIGHT LAST IS: " << last_.GetCoord_(true) << " " << last_.GetCoord_(false) << std::endl;
            std::cout << "AFTER INIT MIDDLE FROM LAST IS: " << (last_.GetLink(false))->GetCoord_(true) << " " << (last_.GetLink(false))->GetCoord_(false) << std::endl; 
            std::cout << "AFTER LINKING AND INIT LAST FROM TMP IS: " << (p_tmp->GetLink())->GetCoord_(true) << " " << (p_tmp->GetLink())->GetCoord_(false) << std::endl;
            std::cout << "FROM F->MIDDLE LAST_ IS: " << ((first_.GetLink())->GetLink())->GetCoord_(true) << "\n";
            std::cout << "---END OF PUSHBACK---" << "\n\n";
        #endif 

    }
}

int Array::GetFirstCoord(bool x = true) const
{
    return first_.GetCoord_(x);
};

int Array::GetLastCoord(bool x = true) const
{
    return (last_.GetCoord_(x)); 
}

int Array::GetIndexCoord(bool x, int num) //to do!!!
{
    std::shared_ptr <ArrNode> tmp {std::make_shared <ArrNode>(first_)};
    #ifdef DEBUG_GIC
        std::cout << "---GetIndexCoord:---\nFirst is: " << first_.GetCoord_(true) << " " << first_.GetCoord_(false) << "\n";
        std::cout << "Last is: " << last_.GetCoord_(true) << " " << last_.GetCoord_(false) << "\n";
        std::cout << "From first_ middle is: " << (first_.GetLink())->GetCoord_(true) << " " << (first_.GetLink())->GetCoord_(false) << std::endl;
        std::cout << "From last_ middle is: " << (last_.GetLink(false))->GetCoord_(true) << " " << (last_.GetLink(false))->GetCoord_(false) << std::endl;
        std::cout << "From l->middle last_ is: " << ((last_.GetLink(false))->GetLink())->GetCoord_(true) << "\n";
        std::cout << "From f->middle last_ is: " << ((first_.GetLink())->GetLink())->GetCoord_(true) << "\n";
    #endif
    for (int i = 0; i < num; ++i) { 
        tmp = tmp->GetLink();       
        std::cout << "the num is: " << i << " " << tmp->GetCoord_(true) << " " << tmp->GetCoord_(false) << std::endl;        
    }
    #ifdef DEBUG_GIC
        std::cout << "---End of GetindexCoord---" << "\n";
    #endif
    return tmp->GetCoord_(x);
};

int Array::TestLeftRight()
{
    ArrNode a = *(first_.GetLink());
    return a.GetCoord_(true);
}

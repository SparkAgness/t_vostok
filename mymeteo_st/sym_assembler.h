		//strings 62, 73, 84 maybe are wrong!! retest them
		//to find nested classes and clear it 
#ifndef SYMBASSEMBLY
#define SYMBASSEMBLY

#include "Change_Arr.h"
#include <string>
#include "Errors.h"

#define X_MIDDLE 14
#define Y_MIDDLE 13

class Symbol final
{
    private:
        Changeable_Array figure_kit_;
        int offset_;//means sequence of symbol at display
        static inline int s_width_{15}; 

        class Symbol_Part
        {
            private:
                Changeable_Array coords_;
            public:
                void Erase_Corner(int, bool);
                //corner allows 1 - left_up corner and further above clockwise (2, 3, 4)
		//rows 1 to 2, false - one corner's cell will be erased, true - three corner's cells will be erased

                Changeable_Array erase_array_; //after Fill_Erase_Array it appears at dyn_array with 1st member - corner coordinate's number in coords_
						     //and 2nd member (optionally) with 2nd and 3d coordinate's numbers in coords_

                void Fill_Erase_Array(int, bool); //OK
                virtual void Rotate_AgainstCW(int) = 0;
                virtual void Fig_Creater() = 0;
                virtual void Mirror(bool, bool) = 0;
            public:
                Symbol_Part();
                virtual ~Symbol_Part();
        };

        class Corner final : public Symbol_Part
        {
            private:
                Changeable_Array coords_;
                Symbol& parent_;
                int side_;
                int sum_offset_; //consists of this->offset + inside offset (by default is 7)
            public:
                void Rotate_AgainstCW(int yield = 1) override
                {
                    int len = coords_.GetLenght();
                    for (int j = 0; j < yield; ++j) {
                        for (int i = 0; i < len; ++i) {
                            int exchangeable = *(coords_.CoordValues(i));
                            coords_.ChangeMember(i, *(coords_.CoordValues(i) + 1), false);
                            //*(*(coords_ + i)) = *(*(coords_ + i) + 1);
                            //*(*(coords_ + i) + 1) = 1 - exchangeable + side_;
                            coords_.ChangeMember(i, 1 - exchangeable + side_, true);
                        }
                    }
                };

                void Fig_Creater() override
                {
                    int y_beg = 2, y_end = 5, x_beg = sum_offset_, x_end = sum_offset_ + 3; 
                    for (int y = y_beg; y <= y_end; ++y) {
                        switch (y) {
                            case 2: {for (int x = x_beg+1; x <= x_end; ++x) {int tmp[2] {x, y}; coords_.PushBack(tmp); break;}}
                            case 3: {for (int x = x_beg; x < x_end - 1; ++x) {int tmp[2] {x, y}; coords_.PushBack(tmp); break;}}
                            default: {int tmp[2] {x_beg, y}; coords_.PushBack(tmp); break;}
                        }
                    }
                };

            public:
                Corner(Symbol& parent, int side = 4, int in_offset = 7) : coords_(0, 0), parent_(parent), side_(side), sum_offset_(in_offset) {sum_offset_ += parent.offset_;};
            void DownCorner();
        };

        class Up_QuartCircle final : public Symbol_Part
        {
            private:
                Changeable_Array coords_;
                Symbol& parent_;
                int sum_offset_;
                void Mirroring(bool hor, bool vert)
                {
                    int arr_lengh = coords_.GetLenght();
                    if (hor && !vert) {
                        for (int i = 0; i < arr_lengh; ++i) {
                        int val = *(coords_.CoordValues(i));
                        coords_.ChangeMember(i, X_MIDDLE*2 - val);}
                    } else if (!hor && vert) {
                        for (int i = 0; i < arr_lengh; ++i) {
                        int val = *(coords_.CoordValues(i) + 1);
                        coords_.ChangeMember(i, true, 2*(Y_MIDDLE + 1) - val);}
                   } else {throw Wrong_Up_QuartCircle(); }//EXCEPTION
		};
            public:
                Up_QuartCircle(Symbol& parent, int in_offset = 7) : coords_(0, 0), sum_offset_(in_offset), parent_(parent) {sum_offset_ += parent_.offset_;};
                void Fig_Creater() override
                {
                    int y_beg = 2, y_end = Y_MIDDLE/2 + 1, x_beg = sum_offset_, x_end = X_MIDDLE;
                    for (int y = y_beg; y <= y_end; ++y) {
                        switch(y) {
                            case 2: {for (int x = x_beg + 4; x <= x_end; ++x){int tmp[2] {x, y}; coords_.PushBack(tmp); break;}}
                            case 3: {for (int x = x_beg + 2; x <= x_end; ++x){int tmp[2] {x, y}; coords_.PushBack(tmp); break;}}
                            case 4: {for (int x = x_beg + 1; x <= x_end - 3; ++x){int tmp[2] {x, y}; coords_.PushBack(tmp); break;}}
                            default: {for (int x = x_beg; x <= x_end - 4; ++x){int tmp[2] {x, y}; coords_.PushBack(tmp); break;}}
                        }
                    }
                };

                void Mirror(bool horiz, bool vertic) override
                {
                    try {Mirroring(horiz, vertic);}
                    catch (Wrong_Up_QuartCircle& ex) {this->Mirroring(0, 1);}
                };
        };

        class Central_Point final : public Symbol_Part
        {
            private:
                Changeable_Array coords_;
                Symbol& parent_;
                int sum_offset_;
            public:
                Central_Point(Symbol& parent, int in_offset = X_MIDDLE - 1) : coords_(0, 0), sum_offset_(in_offset), parent_(parent) {sum_offset_ += parent_.offset_;};
            public:
                void Fig_Creater() override
                {
                    int y_beg = Y_MIDDLE, y_end = Y_MIDDLE + 1, x_beg = sum_offset_, x_end = sum_offset_ + 3;
                    for (int y = y_beg; y <= y_end; ++y) {
                        for (int x = x_beg; x <= x_end; ++x) {int tmp[2] {x, y}; coords_.PushBack(tmp);}
                    }
                };

        };

        class Down_QuartCircle final : public Symbol_Part
	{
            private:
                Changeable_Array coords_;
                Symbol& parent_;
                int sum_offset_;
	    public:
                Down_QuartCircle(Symbol& parent, int in_offset = 7) : coords_(0, 0), sum_offset_(in_offset), parent_(parent) {sum_offset_ += parent_.offset_;};
                void Mirror(bool hor = true, bool vert = false) override
		{
                    int arr_lengh = coords_.GetLenght();
                    if (hor && !vert) {
                        for (int i = 0; i < arr_lengh; ++i) {
                            int val = *(coords_.CoordValues(i));
                            coords_.ChangeMember(i, X_MIDDLE*2 - val);}
                    } else if (!hor && vert) {
                        for (int i = 0; i < arr_lengh; ++i) {
                        int val = *(coords_.CoordValues(i) + 1);
                        coords_.ChangeMember(i, true, 2*(Y_MIDDLE + 1) - val);}
                    }
	        }
	};

        class Vertical_Ln final : public Symbol_Part
	{
            private:
                Changeable_Array coords_;
                Symbol& parent_;
                int sum_offset_;
                int width_; //width of the line, pxs
            public:
                void Rotate_AgainstCW(int) override {};
                void Mirror(bool, bool) override {}; 
                void Fig_Creater() override
                {
                    int y_beg = 2, y_end = Y_MIDDLE*2, x_beg = sum_offset_ + X_MIDDLE - 2, x_end = sum_offset_ + X_MIDDLE + 2;
                    for (int y = y_beg; y <= y_end; ++y) {
                        for (int x = x_beg; x <= x_end; ++x) {int tmp[2] {x, y}; coords_.PushBack(tmp);}
                    }
                };
            public:
                Vertical_Ln(Symbol& parent, int in_offset = X_MIDDLE, int width = 5) : coords_(0, 0), sum_offset_(in_offset), width_(width), parent_(parent) {sum_offset_ += parent_.offset_;}
                void Seven_Creater();
                void Zero_Creater(bool);
                Changeable_Array* GetCoord() {return &coords_;};
	};

        class Horizontal_Ln final : public Symbol_Part
        {
            private:
                Changeable_Array coords_;
                Symbol& parent_;
                int sum_offset_;
                int width_; //widht of the line, pxs
            public:
                Horizontal_Ln(Symbol& parent, int in_offset = 7, int width = 4) : coords_(0, 0), sum_offset_(in_offset), width_(width), parent_(parent) {sum_offset_ += parent_.offset_;};
                void Other_Line_Creater(bool);
            public:
                void Fig_Creater() override //by default is middle line for "4" is created
                {
                    int y_beg = Y_MIDDLE - width_/2, y_end = Y_MIDDLE + width_/2, x_beg = sum_offset_, x_end = sum_offset_ + Symbol::s_width_;
                    for (int y = y_beg; y <= y_end; ++y) {
                        for (int x = x_beg; x <= x_end; ++x) {int tmp[2] {x, y}; coords_.PushBack(tmp);}
                    }
                };
         };

    public:
        Symbol(int offset) : figure_kit_(0, 0), offset_{offset} {};
        static int Get_Swidth() {return Symbol::s_width_;};
	Changeable_Array& Get_Array() {return *figure_kit_;};
        void One();
        void Two();

};

#endif

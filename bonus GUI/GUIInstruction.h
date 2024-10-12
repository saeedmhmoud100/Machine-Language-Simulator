#pragma once

#include <cliext/list>

using namespace System;
using namespace System::Windows::Forms;
using System::Collections::Generic::Stack;

ref class GUIMemory
{
protected:
    array<System::Windows::Forms::Label^>^ arrMemory;

public:
    GUIMemory();
    void clearMemory();
    GUIMemory(array<System::Windows::Forms::Label^>^% MemoryArray);
    void setMemory(int memory_position, String^ value);
    String^ getMemory(int memory_position);
};




ref class GUIRegister : public GUIMemory
{
protected:
    array<System::Windows::Forms::Label^>^ arrRegister;

public:
    GUIRegister(array<System::Windows::Forms::Label^>^% RegistersDataArray,
        array<System::Windows::Forms::Label^>^% MemoryArray);

    void clearRegister();

    GUIRegister();
    void setRegister(char memory_position, String^ value);
    String^ getRegister(char memory_position);
};




ref class GUIInstruction : public GUIRegister {
    ref struct MyStruct
    {
        MyStruct(array<System::Windows::Forms::Label^>^ mm, array<System::Windows::Forms::Label^>^ rr,
            System::Windows::Forms::Label^ ir,
            System::Windows::Forms::Label^ pc)
        {
            m = mm; r = rr; IR = ir; PC = pc;
        }
        array<System::Windows::Forms::Label^>^ m;
        array<System::Windows::Forms::Label^>^ r;
        System::Windows::Forms::Label^ IR;
        System::Windows::Forms::Label^ PC;
    };
private:
    System::Windows::Forms::Label^ IR;
    System::Windows::Forms::Label^ PC;
    bool execute = false;
    int instructionIndex;
    array<String^>^ instructions;
    Stack<MyStruct^>^ history;

public:

    GUIInstruction(array<System::Windows::Forms::Label^>^% RegistersDataArray,
        array<System::Windows::Forms::Label^>^% MemoryArray, System::Windows::Forms::Label^% labelPC
        , System::Windows::Forms::Label^% labelIR);

    void clearData();

    void setInstruction(String^ instruction);
    // void setInstructions(vector<string> instructions);

    void operation_1(String^ s);
    void operation_2(String^ s);
    void operation_3(String^ s);
    void operation_4(String^ s);
    void operation_5(String^ s);
    void operation_B(String^ s);
    void operation_C(String^ s);


    void fetch(array<String^>^ instructions);
    void stepBack();

    void setInstructions(bool all);
    String^ getPC();
    void setPC(String^ s);
    String^ getIR();

};


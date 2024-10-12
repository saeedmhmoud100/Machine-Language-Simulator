#include <iostream>
#include "GUIInstruction.h"
using namespace System;

///////////////////////////////// memory ////////////////////////////////////////
GUIMemory::GUIMemory() {
    array<System::Windows::Forms::Label^>^ t = gcnew array<System::Windows::Forms::Label^>(256);
    this->arrMemory = t;

}
GUIMemory::GUIMemory(array<System::Windows::Forms::Label^>^% MemoryArray) {

    arrMemory = MemoryArray;

    for (int i = 0; i < 256; ++i) {
        (MemoryArray)[i]->Text = "00";
    }
}

void GUIMemory::clearMemory() {
    for (int i = 0; i < 256; ++i) {
        (this->arrMemory)[i]->Text = "00";
    }
}


void GUIMemory::setMemory(int memory_position, String^ value) {
    auto it = arrMemory;
    if (it != nullptr && memory_position >= 0 && memory_position < 256) {
        (arrMemory)[memory_position]->Text = value;
    }
}

String^ GUIMemory::getMemory(int memory_position) {

    if (memory_position >= 0 && memory_position < 256) {
        return arrMemory[memory_position]->Text;
    }

    return "00";
}


///////////////////////////////// Register ////////////////////////////////////////

GUIRegister::GUIRegister() {
    array<System::Windows::Forms::Label^>^ t = gcnew array<System::Windows::Forms::Label^>(16);
    this->arrRegister = t;
}

GUIRegister::GUIRegister(array<System::Windows::Forms::Label^>^% RegistersDataArray,
    array<System::Windows::Forms::Label^>^% MemoryArray) :GUIMemory(MemoryArray) {

    this->arrRegister = RegistersDataArray;

    for (int j = 0; j < 16; ++j) {
        (arrRegister)[j]->Text = "00";
    }
}

void GUIRegister::clearRegister() {

    for (int j = 0; j < 16; ++j) {
        (this->arrRegister)[j]->Text = "00";
    }
}


void GUIRegister::setRegister(char memory_position, String^ value) {
    int index = memory_position - '0';

    if (isalpha(memory_position)) {
        index = memory_position - 55;
    }

    (this->arrRegister)[index]->Text = value;
};


String^ GUIRegister::getRegister(char memory_position) {
    int index = memory_position - '0';
    if (isalpha(memory_position)) {
        index = memory_position - 55;
    }

    return (arrRegister)[index]->Text;
};





///////////////////////////////// Instruction ////////////////////////////////////////

GUIInstruction::GUIInstruction(array<System::Windows::Forms::Label^>^% RegistersDataArray,
    array<System::Windows::Forms::Label^>^% MemoryArray, System::Windows::Forms::Label^% labelPC
    , System::Windows::Forms::Label^% labelIR)
    :GUIRegister(RegistersDataArray, MemoryArray) {
    this->history = gcnew Stack<MyStruct^>;
    this->IR = labelIR;
    this->PC = labelPC;
    this->IR->Text = "0000";
    this->PC->Text = "00";
};

void GUIInstruction::clearData() {
    this->clearMemory();
    this->clearRegister();
    this->IR->Text = "0000";
    this->PC->Text = "00";
};
void GUIInstruction::setInstruction(String^ instruction) {
    if (this->execute) {
        this->IR->Text = "0000";
        return;
    }

    this->IR->Text = instruction;
    String^ s = instruction->Substring(1);

    switch (instruction[0]) {
    case '1':
        operation_1(s);
        break;
    case '2':
        operation_2(s);
        break;
    case '3':
        operation_3(s);
        break;
    case '4':
        operation_4(s);
        break;
    case '5':
        operation_5(s);
        break;
    case 'B':
        operation_B(s);
        break;
    case 'C':
        operation_C(s);
        break;
    }


};
//void GUIInstruction::setInstructions(vector<string> instructions);

void GUIInstruction::operation_1(String^ s) {

    String^ sub = s->Substring(1);

    this->setRegister(sub[0], this->getMemory(Convert::ToInt32(sub)));
};
void GUIInstruction::operation_2(String^ s) {
    String^ sub = s->Substring(1);
    this->setRegister(s[0], sub);
};
void GUIInstruction::operation_3(String^ s) {
    String^ sub = s->Substring(1);
    int num;
    if (Int32::TryParse(sub, System::Globalization::NumberStyles::HexNumber, nullptr, num)) {
        this->setMemory(num, this->getRegister(s[0]));

    }

    //if (s.substr(1) == "00")
    //    this->printMemory();
};
void GUIInstruction::operation_4(String^ s) {
    this->setRegister(s[2], this->getRegister(s[1]));
};

void GUIInstruction::operation_5(String^ s) {
    // Get the hexadecimal strings from the registers
    String^ hex1 = this->getRegister(s[1]);
    String^ hex2 = this->getRegister(s[2]);

    // Convert hexadecimal strings to decimal integers
    int num1, num2;
    int sum;

    if (Int32::TryParse(hex1, System::Globalization::NumberStyles::HexNumber, nullptr, num1) &&
        Int32::TryParse(hex2, System::Globalization::NumberStyles::HexNumber, nullptr, num2)) {
        sum = num1 + num2;

        // Convert the sum back to a hexadecimal string
        String^ hex = sum.ToString("X");

        // Make sure the hexadecimal string is in uppercase
        hex = hex->ToUpper();

        // If the resulting hex is a single character, prepend a '0'
        if (hex->Length == 1) {
            hex = "0" + hex;
        }

        // Set the value to the register
        this->setRegister(s[0], hex->Substring(hex->Length - 2));
    }

    return;
}

void GUIInstruction::operation_B(String^ s) {
    if (this->getRegister(s[0]) == this->getRegister('0')) {

        this->setPC(s->Substring(1)->ToString());
        this->setInstructions(false);
    }
    return;
};


void GUIInstruction::operation_C(String^ s) {
    this->execute = true;
    Application::Exit();
    return;
};

void GUIInstruction::setInstructions(bool all) {
    array<System::Windows::Forms::Label^>^ memo;
    memo = gcnew array<System::Windows::Forms::Label^>(256);

    for (int i = 0; i < 256; i++) {
        memo[i] = gcnew System::Windows::Forms::Label();
        memo[i]->Text = this->getMemory(i);
    }

    array<System::Windows::Forms::Label^>^ regist;
    regist = gcnew array<System::Windows::Forms::Label^>(16);

    for (int i = 0; i < 16; i++) {
        regist[i] = gcnew System::Windows::Forms::Label();
        regist[i]->Text = this->getRegister(i + '0');
    }

    System::Windows::Forms::Label^ pevIR = gcnew System::Windows::Forms::Label;
    System::Windows::Forms::Label^ prevPC = gcnew System::Windows::Forms::Label;
    pevIR->Text = this->IR->Text;
    prevPC->Text = this->PC->Text;

    MyStruct^ s = gcnew MyStruct(memo, regist, pevIR, prevPC);
    this->history->Push(s);
    int pc = Convert::ToInt32(PC->Text);
    int first = pc++;
    int second = pc++;

    //String^ hex1 = first.ToString("X");
    //String^ hex2 = second.ToString("X");

    //hex1 = hex1->ToUpper();
    //hex2 = hex2->ToUpper();

    if (this->getMemory(first) == "00") {
        pc = std::max(0, pc - 2);
        return;
    }
    String^ mem1 = getMemory(first);
    String^ mem2 = getMemory(second);
    this->setInstruction(mem1 + mem2);

    PC->Text = pc.ToString("D2");

    IR->Text = (mem1 + mem2)->ToString();

    if (all)
        setInstructions(all);

};



void GUIInstruction::fetch(array<String^>^ instructions) {
    int pc = Convert::ToInt16(PC->Text);

    int s = pc;
    for each (String ^ instruction in instructions) {
        int sum = pc;

        String^ subInstruction = instruction->Substring(0, 2);
        this->setMemory(pc, subInstruction);
        pc = pc + 1;

        subInstruction = instruction->Substring(2);
        this->setMemory(pc, subInstruction);
        pc = pc + 1;
    }
    pc = s;
    PC->Text = pc.ToString("D2");
}


String^ GUIInstruction::getPC() {
    int pc = Convert::ToInt32(this->PC->Text);
    String^ hex = pc.ToString("X2");
    hex = hex->ToUpper();
    this->PC->Text = pc.ToString();
    return hex;
}

String^ GUIInstruction::getIR() {
    return IR->Text;
}

void GUIInstruction::setPC(String^ s) {
    this->PC->Text = s;
};

void GUIInstruction::stepBack() {
    if (this->history->Count > 0) {
        MyStruct^ temp = this->history->Pop();

        this->IR->Text = temp->IR->Text;
        setPC(temp->PC->Text);

        for (int i = 0; i < 256; i++) {
            this->setMemory(i, temp->m[i]->Text->ToString());
        }
        for (int i = 0; i < 16; i++) {
            this->setRegister(i + '0', temp->r[i]->Text->ToString());
        }
    }
    //else if (this->history->Count == 0) {
    //    this->clearData();
    //}
}

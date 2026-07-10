class ATM {
public:
    vector<int> notes = vector<int>(5, 0);
    ATM() {}

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < notes.size(); i++) {
            notes[i] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        vector<int> temp(5, 0);
        int curr = amount;
        // 500

        int a = curr / 500;

        if (a <= notes[4]) {

            temp[4] = a;

            curr %= 500;

        } else {

            temp[4] = notes[4];

            curr -= notes[4] * 500;
        }

        // 200

        a = curr / 200;

        if (a <= notes[3]) {

            temp[3] = a;

            curr %= 200;

        } else {

            temp[3] = notes[3];

            curr -= notes[3] * 200;
        }

        // 100

        a = curr / 100;

        if (a <= notes[2]) {

            temp[2] = a;

            curr %= 100;

        } else {

            temp[2] = notes[2];

            curr -= notes[2] * 100;
        }

        // 50

        a = curr / 50;

        if (a <= notes[1]) {

            temp[1] = a;

            curr %= 50;

        } else {

            temp[1] = notes[1];

            curr -= notes[1] * 50;
        }

        // 20

        a = curr / 20;

        if (a <= notes[0]) {

            temp[0] = a;

            curr %= 20;

        } else {

            temp[0] = notes[0];

            curr -= notes[0] * 20;
        }
        if (curr == 0) {
            for (int i = 0; i < 5; i++) {
                notes[i] -= temp[i];
            }
            return temp;
        }
        return {-1};
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
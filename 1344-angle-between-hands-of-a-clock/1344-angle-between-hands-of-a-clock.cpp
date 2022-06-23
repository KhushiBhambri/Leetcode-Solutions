class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour= hour%12;
        double HinH = double(360)/12;
        double HinM = double(360)/(12*60);
        double MinM = double(360)/60;
        // cout<<HinH<<" "<<HinM<<endl;
        double H = hour*HinH + HinM*minutes;
        double M = MinM*minutes;
        double angle = abs(M-H);
        // cout<<H<<" "<<M<<endl;
        return min(angle,360-angle);
    }
};
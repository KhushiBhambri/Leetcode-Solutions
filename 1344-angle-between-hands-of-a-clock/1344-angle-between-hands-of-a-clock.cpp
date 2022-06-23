class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour= hour%12;
        double HinH = double(360)/12;  // degrees moved by hour hand in 1 hour
        double HinM = double(360)/(12*60);  // deg moved by hour hand in 1 min
        double MinM = double(360)/60;     // deg moved by min hand in 1 min.
        double H = hour*HinH + HinM*minutes;
        double M = MinM*minutes;
        double angle = abs(M-H);
        return min(angle,360-angle);
    }
};
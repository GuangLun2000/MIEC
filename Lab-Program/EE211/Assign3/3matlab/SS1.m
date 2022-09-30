%% Assign3 Hanclin Cai 832002117
% The dataset given to me by the TA is: A = 4; B1 = 10; B2 =25
% Statement: All the Code and Pic were created by myself, and I never share with others.

%% Q4-Q5
% ����ϵͳ״̬�ռ���ʽģ�� State-Space Modelling
A = [0 1 ; -25 -10];
B = [0;1];
C = [-4 4];
D = 0;
G = ss(A,B,C,D);  % Continuous-time state-space model.
% step(G,5)   % using a unit step input

% ϵͳ����ʽ��ʽ�Ĵ��ݺ���ģ�� sys1
sys1 = tf(G);  % Continuous-time transfer function.

% ϵͳ��-������ʽ�Ĵ��ݺ���ģ�� sys2
sys2 = zpk(sys1);  % Continuous-time zero/pole/gain model.

% ϵͳ���ݺ�������ʽ��ʽ�ķ��ӡ���ĸ����ʽϵ��
[num ,den] = ss2tf(A,B,C,D);  % Numerator and denominator polynomial coefficients

% ϵͳ��-����: zΪ��㣬pΪ����
[z,p] = ss2zp(A,B,C,D);  % z is the zero point, and p is the pole.


%% Q8 
% calculate the poles of the closed loop system.

syms s;
sys11 = s^2 + 10*s + 2;
% root(sys11,s);
poles = solve(sys11,s);  % poles = -5 & -5

%% Q9 
% determine a state-space representation for the closed-loop transfer function (CLTF) for the system in Fig.A1 \
% and calculate the eigenvalues of this system.

k = 2;  % when k = 2, the system is asymptotically stable
sign = -1;  
SYS = feedback(G,k,sign);
SYS1 = tf(SYS);  % Continuous-time transfer function.
eigvalues = eig(SYS);  % when k = 2, eigvalues = -1 & -17

k1 = -5/2;  % when k = -5/2, the system become marginally stable.
SYS2 = feedback(G,k1,sign);
SYS22 = tf(SYS2);


%% EE211 Assignment3 MATLAB code by Hanlin Cai

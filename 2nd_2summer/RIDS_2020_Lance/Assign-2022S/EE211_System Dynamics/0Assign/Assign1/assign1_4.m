%% Assign1-3 2022/05/03 Hanlin Cai
% FFT���ٸ���Ҷ�任������������
% Fast Fourier Transform

clear;clc;close all;

%% 1�����뽨ģѵ����
% Import the modeling training set

data1 = importdata('2data/Gr3.txt');
data2 = data1.data;
data3 = data2(1:1000,:);
data4 = data2(1001:2000,:);

t1 = data3(:,1); %time_1
u1 = data3(:,2); %input_1
y1 = data3(:,3); %output_1

t2 = data4(:,1); %time_2
u2 = data4(:,2); %input_2
y2 = data4(:,3); %output_2

Ts = 1000;
ze = iddata(y1,u1,Ts);
zv = iddata(y2,u2,Ts);

NN = struc(1:3, 1:3, 0:2);
V = arxstruc(ze,zv,NN);

%% ��֤ģ�;�׼�ȣ�ͬA1-1

% order = selstruc(V,0);
% M = iv4(ze,order);


%% ��������
% 1�����ȷֲ�����
u2 = u1 + 0.1*(2*rand(size(u1))-1).*u1; 

% 2����̬�ֲ�����
u3 = u1 + 0.1*randn(size(u1)).*(u1);

%% FFT����

% 1�����źŽ���fft�任����ȡ�ź�Ƶ�ʷֲ�
L=length(u1);
T=(u1(end)-u1(1))/L; % �������ڵ��ڲ������ȳ�ȥ��������
Fs1=1/T; % ����Ƶ��
f1=Fs1*(0:(L/2))/L;

L=length(u2);
T=(u2(end)-u2(1))/L; % �������ڵ��ڲ������ȳ�ȥ��������
Fs2=1/T; % ����Ƶ��
f2=Fs2*(0:(L/2))/L;


% 2������Ҷ�任
S1=y1(1:L);
Y1 = fft(S1);
P2 = abs(Y1/L);
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);

S2=y2(1:L);
Y2 = fft(S2);
P3 = abs(Y2/L);
P4 = P3(1:L/2+1);
P4(2:end-1) = 2*P4(2:end-1);

% 3��plot
figure;
plot(f1,P1)
% plot(f2,P4)
% title('FFT')
xlabel('f (Hz)')
ylabel('y')

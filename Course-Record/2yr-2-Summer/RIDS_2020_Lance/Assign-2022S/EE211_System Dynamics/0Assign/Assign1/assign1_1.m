%% Assign1-1 2022/05/03 Hanlin Cai
% ʹ��Matlba���ú���������ϣ����ж���Ͼ���
% Use struc & arxstruc (ARX) function to fit the model
% Then verify the fitting accuracy

clear;clc;close all;

%% 1�����뽨ģѵ����
% Import the modeling training set

data1 = importdata('2data/Gr3.txt');
data2 = data1.data;
data3 = data2(1:1000,:);
data4 = data2(2001:3000,:);

t1 = data3(:,1); %time_1
u1 = data3(:,2); %input_1
y1 = data3(:,3); %output_1


t2 = data4(:,1); %time_2
u2 = data4(:,2); %input_2
y2 = data4(:,3); %output_2

% plot(t2,y2,'o')
plot(t1,y1,'-')
xlabel('t')
ylabel('y')
title('Original corresponding curve');

Ts = 1000;
ze = iddata(y1,u1,Ts);
zv = iddata(y2,u2,Ts);

NN = struc(1:3, 1:3, 0:2);
V = arxstruc(ze,zv,NN);

order = selstruc(V,0);
M1 = arx(zv,order)


%% 2��ʹ�þ�������磬����ģ�ͱ���
% Convolutional neural networks are used to compute model representations.

% [u1, t1] = bodyfat_dataset;
% net = feedforwardnet(10);
% net.performParam.regularization = 0.01;
% net.performFcn
% 
% net = train(net, u1, t1);
% y = net(u1);
% perf = perform(net, t2, y2)


%% 3����������
% Increase the noise

% 1�����ȷֲ����� Uniformly distributed noise
u3 = u1 + 0.1*(2*rand(size(u1))-1).*u1; 

% 2����̬�ֲ����� Normally distributed noise
u4 = u2 + 0.1*randn(size(u2)).*(u2);


%% 4����֤ģ�;�׼��
% Verify model accuracy

order = selstruc(V,0);
M1 = arx(zv,order)

% �������������źŲ���
Z1 = iddata(y1,u1,0.05);
Z2 = iddata(y1,u3,0.05);
Z3 = iddata(y1,u4,0.05);
% Z4 = iddata(y2,u1,0.05);

% M2 = arx(Z1 , [5,6,0])
% compare(M2, Z1);
% hold on;

%% 5������Loss Function
% ident;
% u1 y1 
% u2 y2
% u3 y1 noise
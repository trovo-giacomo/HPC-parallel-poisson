clear all;
close all;
clc;

load("exp3_jacobi.dat");

figure;
grid on;
hold on;
xlabel("Number of threads");
ylabel("Speedup");
title("N=120 - max iter=8000");
plot(exp3_jacobi(1,2:end),exp3_jacobi(1,2:end));
for i  = 2:7
    speedup = exp3_jacobi(i,1)./exp3_jacobi(i,2:end);
    plot(exp3_jacobi(1,2:end),speedup);
end

legend("Amdahl's law","baseline","collapse 2","collapse 3","parallel init","parallel init - cores","parallel init - sockets");

%%
load("exp3_jacobi_2.dat");

figure;
grid on;
hold on;
title("N=700 - maxiter=100");
xlabel("Number of threads");
ylabel("Speedup");
plot(exp3_jacobi(1,2:end),exp3_jacobi(1,2:end));
for i  = 2:7
    speedup = exp3_jacobi_2(i,1)./exp3_jacobi_2(i,2:end);
    plot(exp3_jacobi_2(1,2:end),speedup);
end

legend("Amdahl's law","baseline","collapse 2","collapse 3","parallel init","parallel init - cores","parallel init - sockets");
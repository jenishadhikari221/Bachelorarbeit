import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit 
from statsmodels.graphics.tsaplots import plot_acf

def linear_fit(x,a,b):
    return x*a+b
def dU_dT(data_U,delta_U,data_T):
    popt,pcov = curve_fit(linear_fit,data_T,data_U,sigma=delta_U)
    return popt[0], np.sqrt(pcov[0,0])

def exponential_fit(xdata,a,b):
    return a*xdata**b
def onsager_soluttion(Beta):
    Tc = 2.269
    temp = np.array([])
    for B in Beta:
        if(1/B>Tc):
            temp = np.append(temp,0)
        else:    
            temp = np.append(temp,(1-(np.sinh(2*B)**(-4)))**(1/8))
  
    return temp
def chi_sq(fun,xdata,ydata,y_err,popt):
    chi_squred = sum((ydata-fun(xdata,*popt))**2/y_err**2)
    chi_squred_ndf = chi_squred/(len(ydata)-len(popt))
    return chi_squred_ndf

def data_blocking(data,l):
    N = data.size
    blocked_data = np.array([])
    for i in range(0,N,l):
        a = np.mean(data[i:i+l])
        blocked_data = np.append(blocked_data,a)
    
    return blocked_data

def bootstrap_data(data):
    N = data.size
    new_data = np.zeros(N)
    for i in range(N):
        new_data[i] = data[np.random.randint(0,N-1)] 
    return new_data

def autocorr(data,lag):
    mean = np.mean(data)
    C_0 = np.mean((data-mean)**2)
    if(C_0 == 0):
        return 0
    if(lag>0):
        C_X = np.mean((data[lag:]-mean)*(data[:-lag]-mean))
    else:
        C_X = np.mean((data-mean)**2)
    return C_X/C_0

def autocorr_array(data,lag):
    x= np.zeros(lag)
    for i in range(lag):
        x[i] = autocorr(data,i)
    return x

def data_blocking_error(data,length):
    result = np.zeros((3,length))
    for i in range(1,length):
        N =len(data)
        x = []
        for j in range(0,N,i):
            a = data[j:j+i]
            x.append(np.std(a))
        result[0,i] = i
        result[1,i] = np.mean(x)
        result[2,i] = np.std(x)/np.sqrt(len(x))
   
    return result
def bootstrap_mean_and_error(data,block_len,boot_length):
    array1 = np.array([])
    new_data = data_blocking(data,block_len)
    for _ in range(boot_length):
        array1 = np.append(array1,np.mean(bootstrap_data(new_data)))
    mean = np.mean(array1)
    std = np.sqrt(sum((array1-mean)**2)/(len(array1)-1))
    return mean,std

def binder_cummulanten(Spin,block_len=None,boot_length=None):
    Spin_2 = Spin**2
    Spin_4 = Spin**4  
    m_4,m_4_err = bootstrap_mean_and_error(Spin_4,block_len,boot_length)
    m_2,m_2_err = bootstrap_mean_and_error(Spin_2,block_len,boot_length)
    M_2 = m_2**2
    binder_cumm = 1-m_4/(3*M_2)
    binder_error = np.sqrt((m_4_err/(3*M_2))**2+(2*m_4*m_2_err/(3*M_2*m_2))**2)
    return binder_cumm,binder_error



def variance(data,block_len,boot_length):
    a,delta_a = bootstrap_mean_and_error(data**2,block_len,boot_length)
    b,delta_b = bootstrap_mean_and_error(data,block_len,boot_length)
    var = a - b**2
    delta_var = np.sqrt(delta_a**2+(2*b*delta_b)**2)
    return var,delta_var

def binder_cum_plot(spin_simulation,block_len=None,color='r',format='.',boot_length=None,label=None):
    temp_dim = spin_simulation.shape[1]
    new_array = np.array([])
    new_array_err = np.array([])
    for i in range(temp_dim):
        x_achse = 1/spin_simulation[0,i]
        new_data = spin_simulation[1:,i]
        y_data,y_data_err = binder_cummulanten(new_data,block_len=block_len,boot_length=boot_length)
        new_array = np.append(new_array,y_data)
        new_array_err = np.append(new_array_err,y_data_err)
        if(i<(temp_dim-1)):
            plt.errorbar(x_achse,y_data,yerr=y_data_err,c=color,fmt=format)
        
        else:
            plt.errorbar(x_achse,y_data,yerr=y_data_err,c=color,fmt=format,label=label)
        
    return new_array,new_array_err



def spin_simulation_plot(spin_simulation,block_len = 100,color='r',format='.',boot_length=1,label=None):
    temp_dim = spin_simulation.shape[1]
    for i in range(temp_dim):
        x_achse = 1/spin_simulation[0,i]
        spin_data = spin_simulation[1:,i]
        y_data,y_err = bootstrap_mean_and_error(spin_data,block_len,boot_length)
        if(i<(temp_dim-1)):
            plt.errorbar(x_achse,y_data,yerr=y_err,c=color,fmt=format)
        
        else:
            plt.errorbar(x_achse,y_data,yerr=y_err,c=color,fmt=format,label=label)
    return

def specfic_heat_plot(spin_simulation,block_len = 100,color='r',format='.',boot_length=2,label=None,N=1):
    temp_dim = spin_simulation.shape[1]
    new_array = np.array([])
    new_array_err = np.array([])
    for i in range(temp_dim):
        beta = spin_simulation[0,i]
        x_achse = 1/beta
        new_data = spin_simulation[1:,i]
        y_data,y_data_err = variance(new_data,block_len,boot_length)
        y_data,y_data_err = y_data*beta**2/N,y_data_err*beta**2/N
        new_array = np.append(new_array,y_data)
        new_array_err = np.append(new_array_err,y_data_err)
        if(i<(temp_dim-1)):
            plt.errorbar(x_achse,y_data,yerr=y_data_err,c=color,fmt=format)
        
        else:
            plt.errorbar(x_achse,y_data,yerr=y_data_err,c=color,fmt=format,label=label)
    return new_array,new_array_err

def magnetic_sus_plot(spin_simulation,block_len = 100,color='r',format='.',boot_length=2,label=None,N=1):
    temp_dim = spin_simulation.shape[1]
    new_array = np.array([])
    new_array_err = np.array([])
    for i in range(temp_dim):
        beta = spin_simulation[0,i]
        x_achse = 1/beta
        new_data = spin_simulation[1:,i]
        y_data,y_data_err = variance(new_data,block_len,boot_length)
        y_data,y_data_err = y_data*beta/N,y_data_err*beta/N
        new_array = np.append(new_array,y_data)
        new_array_err = np.append(new_array_err,y_data_err)
        if(i<(temp_dim-1)):
            plt.errorbar(x_achse,y_data,yerr=y_data_err,c=color,fmt=format)
        
        else:
            plt.errorbar(x_achse,y_data,yerr=y_data_err,c=color,fmt=format,label=label)
    return new_array,new_array_err

def critical_temp_error(SPINS,temp_left_bound,temp_right_bound,block_len,bootstrap_number,boot_length):
    dim = SPINS.shape[0]
    temp = 1/SPINS[1,0,:]
    indx = (temp>=temp_left_bound) & (temp<=temp_right_bound)
    new_temp = temp[indx]
    binder_cum = np.array([])
    binder_cum_error = np.array([])
    new_x  = np.linspace(temp_left_bound,temp_right_bound,600)
    new_temp = new_temp[::-1]
    data = SPINS[:,1:,indx]
    for _ in range(bootstrap_number):
        temp_array = np.array([])
        for i in range(dim):
            y1 = np.array([binder_cummulanten(bootstrap_data(data[i,:,0]),block_len=block_len,boot_length=boot_length)[0],binder_cummulanten(bootstrap_data(data[i,:,1]),block_len=block_len,boot_length=boot_length)[0]])
            a1 = np.interp(new_x,new_temp,y1[::-1])
            j = i
            while j != dim-1:
                y2 = np.array([binder_cummulanten(bootstrap_data(data[j+1,:,0]),block_len=block_len,boot_length=boot_length)[0],binder_cummulanten(bootstrap_data(data[j+1,:,1]),block_len=block_len,boot_length=boot_length)[0]])
                a2 = np.interp(new_x,new_temp,y2[::-1])
                dif1 = np.where(abs(a1-a2) == min(abs(a1-a2)))[0][0]
                j +=1
                temp_array = np.append(temp_array,new_x[dif1])
        binder_cum = np.append(binder_cum,np.mean(temp_array))
        binder_cum_error = np.append(binder_cum_error,np.std(temp_array))

    return np.mean(binder_cum),np.sqrt(max(binder_cum_error)**2+(np.std(binder_cum_error))**2)

        
        







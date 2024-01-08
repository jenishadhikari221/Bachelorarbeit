import numpy as np
import matplotlib.pyplot as plt

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

def binder_cummulanten(Spin):
    m_4 = np.mean(Spin**4)
    m_2 = np.mean(Spin**2)
    M_2 = m_2**2
    m_3 = np.mean(Spin**3)
    binder_cumm = 1-m_4/(3*M_2)
    #error = np.abs((4*m_2*m_3)-(4*m_4*m_2*np.mean(Spin)))/(3*M_2**2)*np.std(Spin)
    return binder_cumm



def specific_heat(data,beta,L):
    temp = (np.std(data)**2)*beta**2/(L**2)
    return temp

def binder_cum_plot(spin_simulation,color='r',format='.',boot_length=None,label=None):
    temp_dim = spin_simulation.shape[1]
    new_array = np.array([])
    for i in range(temp_dim):
        x_achse = 1/spin_simulation[0,i]
        new_data = spin_simulation[1:,i]
        block_len = block_length(new_data)
        new_data = data_blocking(new_data,block_len)
        new_data2 = np.array([])
        for _ in range(block_len):
            new_data2 = np.append(new_data2,bootstrap_data(new_data))
        y_data = binder_cummulanten(new_data2)
        binder_error = np.array([])
        for _ in range(boot_length):
            binder_error = np.append(binder_error,binder_cummulanten(bootstrap_data(new_data)))

        new_array = np.append(new_array,y_data)
        y_err = np.std(binder_error)
        if(i<(temp_dim-1)):
            plt.errorbar(x_achse,y_data,yerr=y_err,c=color,fmt=format)
        
        else:
            plt.errorbar(x_achse,y_data,yerr=y_err,c=color,fmt=format,label=label)
        
    return new_array

def binder_cum_plot_without_block(spin_simulation,color='r',format='.',boot_length=None,label=None):
    temp_dim = spin_simulation.shape[1]
    new_array = np.array([])
    for i in range(temp_dim):
        x_achse = 1/spin_simulation[0,i]
        new_data = spin_simulation[1:,i]
        y_data = binder_cummulanten(new_data)
        binder_error = np.array([])
        for _ in range(boot_length):
            binder_error = np.append(binder_error,binder_cummulanten(bootstrap_data(new_data)))
        new_array = np.append(new_array,y_data)
        y_err = np.std(binder_error)
        if(i<(temp_dim-1)):
            plt.errorbar(x_achse,y_data,yerr=y_err,c=color,fmt=format)
        
        else:
            plt.errorbar(x_achse,y_data,yerr=y_err,c=color,fmt=format,label=label)
        
    return new_array

def binder_cum_plot_same_length(spin_simulation,color='r',format='.',boot_length=None,label=None):
    temp_dim = spin_simulation.shape[1]
    new_array = np.array([])
    arr = []
    for i in range(spin_simulation.shape[1]):
        auto = autocorr_array(spin_simulation[1:,i],lag=1000)
        a = np.where(auto <0.01)[0]
        if(a[0] != 0):
            arr.append(a[0])
    block_len = max(arr)
    for i in range(temp_dim):
        x_achse = 1/spin_simulation[0,i]
        new_data = spin_simulation[1:,i]
        new_data = data_blocking(new_data,block_len)
        new_data2 = np.array([])
        for _ in range(block_len):
            new_data2 = np.append(new_data2,bootstrap_data(new_data))
        y_data = binder_cummulanten(new_data2)
        binder_error = np.array([])
        for _ in range(boot_length):
            binder_error = np.append(binder_error,binder_cummulanten(bootstrap_data(new_data)))

        new_array = np.append(new_array,y_data)
        y_err = np.std(binder_error)
        if(i<(temp_dim-1)):
            plt.errorbar(x_achse,y_data,yerr=y_err,c=color,fmt=format)
        
        else:
            plt.errorbar(x_achse,y_data,yerr=y_err,c=color,fmt=format,label=label)
        
    return new_array


def spin_simulation_plot(spin_simulation,color='r',format='.',boot_length=1,label=None):
    temp_dim = spin_simulation.shape[1] 
    for i in range(temp_dim):
        x_achse = 1/spin_simulation[0,i]
        new_data = spin_simulation[1:,i]
        block_len = block_length(new_data)
        new_data = data_blocking(new_data,block_len)
        new_data2 = np.array([]) 
        for _ in range(block_len): 
            new_data2 = np.append(new_data2,bootstrap_data(new_data))
        if(i<(temp_dim-1)):
            plt.errorbar(x_achse,np.mean(new_data2),yerr=np.std(new_data2),c=color,fmt=format)
        
        else:
            plt.errorbar(x_achse,np.mean(new_data2),yerr=np.std(new_data2),c=color,fmt=format,label=label)
        

    return

def specfic_heat_plot_without_block(spin_simulation,color='r',format='.',boot_length=2,label=None,L=1):
    temp_dim = spin_simulation.shape[1]
    new_array = np.array([])
    for i in range(temp_dim):
        x_achse = 1/spin_simulation[0,i]
        new_data = spin_simulation[1:,i]
        new_data2 = specific_heat(new_data,spin_simulation[0,i],L)
        new_array = np.append(new_array,new_data2)
        error = np.array([]) 
        for _ in range(boot_length): 
            error = np.append(error,specific_heat(bootstrap_data(new_data),spin_simulation[0,i],L))
        y_err = np.std(error)
        if(i<(temp_dim-1)):
            plt.errorbar(x_achse,new_data2,yerr=y_err,c=color,fmt=format)
        
        else:
            plt.errorbar(x_achse,new_data2,yerr=y_err,c=color,fmt=format,label=label)
        
    return new_array

def specfic_heat_plot_same_length(spin_simulation,color='r',format='.',boot_length=2,label=None,L=1):
    temp_dim = spin_simulation.shape[1]
    new_array = np.array([])
    arr = []
    for i in range(spin_simulation.shape[1]):
        auto = autocorr_array(spin_simulation[1:,i],lag=1000)
        a = np.where(auto <0.01)[0]
        if(a[0] != 0):
            arr.append(a[0])
    block_len = max(arr)

    for i in range(temp_dim):
        x_achse = 1/spin_simulation[0,i]
        new_data = spin_simulation[1:,i]
        new_data = data_blocking(new_data,block_len)
        new_data2 = specific_heat(new_data,spin_simulation[0,i],L)
        new_array = np.append(new_array,new_data2)
        error = np.array([]) 
        for _ in range(boot_length): 
            error = np.append(error,specific_heat(bootstrap_data(new_data),spin_simulation[0,i],L))
        y_err = np.std(error)
        if(i<(temp_dim-1)):
            plt.errorbar(x_achse,new_data2,yerr=y_err,c=color,fmt=format)
        
        else:
            plt.errorbar(x_achse,new_data2,yerr=y_err,c=color,fmt=format,label=label)
        
    return new_array

def specfic_heat_plot_diff_length(spin_simulation,color='r',format='.',boot_length=2,label=None,L=1):
    temp_dim = spin_simulation.shape[1]
    new_array = np.array([])
    for i in range(temp_dim):
        x_achse = 1/spin_simulation[0,i]
        new_data = spin_simulation[1:,i]
        new_data = data_blocking(new_data,block_length(new_data))
        new_data2 = specific_heat(new_data,spin_simulation[0,i],L)
        new_array = np.append(new_array,new_data2)
        error = np.array([]) 
        for _ in range(boot_length): 
            error = np.append(error,specific_heat(bootstrap_data(new_data),spin_simulation[0,i],L))
        y_err = np.std(error)
        if(i<(temp_dim-1)):
            plt.errorbar(x_achse,new_data2,yerr=y_err,c=color,fmt=format)
        
        else:
            plt.errorbar(x_achse,new_data2,yerr=y_err,c=color,fmt=format,label=label)
        
    return new_array

def block_length(data):

    auto = autocorr_array(data,lag=1000)
    a = np.where(auto <0.01)[0]
    if(a[0] != 0):
        return a[0]
    return 1
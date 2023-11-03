using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

//BackgroundWorker
using System.ComponentModel;
//Thread.Sleep
using System.Threading;
//Delegate
using System.Windows.Threading;
//DashBoard_Client class
using DashBoard_Client;

namespace DashBoard
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window
    {
        //Connect 연결 후 스레드.
        BackgroundWorker motionThread = new BackgroundWorker();
        //서버로부터 데이터처리 스레드
        BackgroundWorker updateThread = new BackgroundWorker();
		//뒤로가기 버튼
		bool back_true = false;
		
        //소켓 통신
        DashBoardClient client =  new DashBoardClient();
 
        public MainWindow()
        {
            InitializeComponent();

            //connection_motion 동작 함수 초기화
            motionThread.DoWork += UIChangeWorker;
            //update 워커 초기화
            updateThread.DoWork += UpdateWorker;
			updateThread.WorkerSupportsCancellation = true; //취소 가능 여부
        }

		
        //Connect 연결시 UI 모션
        private void UIChangeWorker(object sender, DoWorkEventArgs e)
        {
            //Main UI에 접근하기위해
            Dispatcher.Invoke(DispatcherPriority.Normal, new Action(delegate
            {
                StartForm_grid.Opacity = 0;
				StartForm_grid.IsEnabled = false;
            }));
            for (double i = 0; i <= 1; i += 0.007)
            {
                //Main UI에 접근하기위해
                Dispatcher.Invoke(DispatcherPriority.Normal, new Action(delegate
                {
                        DashBoard_grid.Opacity = i;
                }));
                Thread.Sleep(1);
            }
            updateThread.RunWorkerAsync();
        }

        //서버 리소스 정보를 받아온다.
        private void UpdateWorker(object sender, DoWorkEventArgs e)
        {
            ResourceInfo res = null;
			
			const double MB = 1024*1024.0;
			const double kBytes = 1024.0;
			
			
			double cpu_Chart_val = 0
					, mem_Chart_val = 0
					, vir_Chart_val = 0;
			
            while(true)
            {
				//작업 취소 요청이 왔을 경우.
				if(updateThread.CancellationPending)
					break;
				
				res = null;
                res = client.Get_Resource_Data();
				Dispatcher.Invoke(DispatcherPriority.Normal, new Action(delegate
                {
					//CPU 정보
					Cpu_model_label.Content = Encoding.ASCII.GetString(res.cpuModel, 0, 50);
					Cpu_core_label.Content = Encoding.ASCII.GetString(res.cpuCoreCount, 0, 3);
					
					//Memory 정보
					//	물리메모리
					total_phy_mem_label.Content = (res.memoryTotalSize / MB).ToString("N0") + " MB";
					use_phy_mem_label.Content   = (res.memoryUsageSize / MB).ToString("N4") + " MB";
					//	가상메모리
					total_vir_mem_label.Content = (res.virtualMemoryTotalSize / MB).ToString("N0") + " MB";
					use_vir_mem_label.Content   = (res.virtualMemoryUsageSize / MB).ToString("N4") + " MB";
					
					//Network 정보
					// 바이트
					Input_bytes_label.Content  = (res.networkRecvSizePerSecond).ToString() + " Bytes/s";
					Output_bytes_label.Content = (res.networkSendSizePerSecond).ToString() + " Bytes/s";
					Total_bytes_label.Content  = (res.networkTotalSizePerSecond).ToString() + " Bytes/s";
					// 소켓
					Input_sock_label.Content  = (res.networkRecvPacketPerSecond).ToString() + " (1/s)";
					Output_sock_label.Content = (res.networkSendPacketPerSecond).ToString() + " (1/s)";
					Total_sock_label.Content  = (res.networkTotalPacketPerSecond).ToString() + " (1/s)";
					
					//송수신 최고 기록.
					// 바이트
					Input_Maxbyte_label.Content  = (res.networkMaximumRecvSize / kBytes).ToString("N0") + " KBytes/s";
					Output_Maxbyte_label.Content = (res.networkMaximumSendSize / kBytes).ToString("N0") + " KBytes/s";
					// 소켓
					Input_Maxsock_label.Content  = (res.networkMaximumRecvPacket).ToString() + " (1/s)";
					Output_Maxsock_label.Content = (res.networkMaximumSendPacket).ToString() + " (1/s)";
					

                    //CPU Chart
					cpu_usage_label.Content = (res.cpuUsage).ToString() + "%";
					cpu_Chart_val  = res.cpuUsage * -3.6;
					cpu_usage_bar.StartAngle = (cpu_Chart_val == 0) ? -1 : cpu_Chart_val;

                    //Memory Chart
					mem_Chart_val = (res.memoryUsageSize * 100) / res.memoryTotalSize;
					mem_usage_label.Content = ((int)mem_Chart_val).ToString() + "%";
					mem_usage_bar.StartAngle = (mem_Chart_val == 0) ? -1 : mem_Chart_val * -3.6;
 
					//Virtual Memory Chart
					vir_Chart_val = (res.virtualMemoryUsageSize* 100) / res.virtualMemoryTotalSize;
					virtualMem_usage_label.Content = ((int)vir_Chart_val).ToString() + "%";
					virtualMem_usage_bar.StartAngle = (vir_Chart_val == 0) ? -1 : vir_Chart_val * -3.6;
                }));
            }

        }
       

        //Connect Button
        private void Start_btn_Click(object sender, System.Windows.RoutedEventArgs e)
        {
        	// TODO: 여기에 구현된 이벤트 처리기를 추가하십시오.
            //ip Address Make
            string ipAddress = IP_box_1.Text + "." + IP_box_2.Text + "."
                               + IP_box_3.Text + "." + IP_box_4.Text;

            try
            {
                client.Connecting(ipAddress);		//서버 연결
                motionThread.RunWorkerAsync();	//UI 교체 스레드 시작.
            	back_true = true;	//Back 버튼 기능 활성화
			}
            catch(Exception error)
            {
                MessageBox.Show(error.Message);
            }
        }

        private void close_Btn_Click(object sender, System.Windows.RoutedEventArgs e)
        {
        	this.Close();
        }

        private void back_Btn_Click(object sender, System.Windows.RoutedEventArgs e)
        {
			if(back_true)
			{
					try{
						updateThread.CancelAsync();
						client.Close();
						back_true = false;
						StartForm_grid.IsEnabled = true;
						
                		StartForm_grid.Opacity = 1;
						DashBoard_grid.Opacity = 0;
					} catch (Exception error)
					{
						MessageBox.Show(error.Message);
					}
			}
        }
    }
}

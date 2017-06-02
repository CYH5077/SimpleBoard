using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//MarshalAs
using System.Runtime.InteropServices;
//Socket
using System.Net;
using System.Net.Sockets;

namespace DashBoard_Client
{
    //자원 정보를 저장할 구조체
    [StructLayout(LayoutKind.Sequential)]
    public class resource_info
    {
        public double total_mem;
        public double using_mem;
        public double total_vir_mem;
        public double using_vir_mem;

        public int cpu;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 50)]
        public byte[] cpu_model;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 3)]
        public byte[] cpu_core_count;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 20)]
        public byte[] cpu_vendor;

        public int netSec_recv; //초당 받은 데이터.
        public int netSec_send; //초당 전송한 데이터
        public int netSec_total; //초당 전송,받은 데이터
        public int netSec_max_send; //초당 최고치를 기록한 전송 바이트.
        public int netSec_max_recv; //초당 최고치를 기록한 수신 바이트
        public int netSec_max_total; //초당 전송,받은 데이터의 최대 크기.

        public int netSock_recv; //초당 전송한 패킷
        public int netSock_send; //초당 수신한 패킷
        public int netSock_total; //초당 전송 및 수신 패킷
        public int netSock_max_send; //초당 최고치를 기록한 전송패킷 수
        public int netSock_max_recv; //초당 최고치를 기록한 수신패킷 수
        public int netSock_max_total; //초당 전송, 받은 데이터의 최대 개수.

    };

    class DashBoardClient
    {

        private TcpClient mySock = null;
        private NetworkStream myStream = null;
		
		
/// ////
        public DashBoardClient()
        {
            //Connecting(ipAddress);
        }
        ~DashBoardClient()
        {
            if (myStream != null)
                myStream.Close();

            if (mySock != null)
                mySock.Close();
        }
 ///////
		
        //접속 요청
        public void Connecting(string ipAddress)
        {
            try
            {
                mySock = new TcpClient(ipAddress, 36555);
                myStream = mySock.GetStream();
            }
            catch (Exception e)
            {
                myStream.Close();
                mySock.Close();
                throw new Exception(e.Message);
            }
        }

        //데이터를 받아온다.
        public resource_info Get_Resource_Data()
        {
			resource_info serv_resource = new resource_info();
            byte[] buffer = new byte[Marshal.SizeOf(serv_resource)];
			
			try
            {
                //서버로 부터 데이터를 받는다.
                myStream.Read(buffer, 0, Marshal.SizeOf(serv_resource));
            }
            catch(Exception e)
            {
                throw new Exception(e.Message);
            }

            unsafe
            {
                fixed (byte* fixed_buffer = buffer)
                    Marshal.PtrToStructure((IntPtr)fixed_buffer, serv_resource);
            }
            return serv_resource;
        }
		
		public void Close()
		{
			myStream.Close();
			mySock.Close();
		}
    }
}

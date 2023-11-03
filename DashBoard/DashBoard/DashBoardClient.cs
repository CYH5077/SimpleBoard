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
    public class ResourceInfo
    {
        public double memoryTotalSize;
        public double memoryUsageSize;
        public double virtualMemoryTotalSize;
        public double virtualMemoryUsageSize;

        public int cpuUsage;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 50)]
        public byte[] cpuModel;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 3)]
        public byte[] cpuCoreCount;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 20)]
        public byte[] cpuVendor;

        public int networkRecvSizePerSecond; //초당 받은 데이터.
        public int networkSendSizePerSecond; //초당 전송한 데이터
        public int networkTotalSizePerSecond; //초당 전송,받은 데이터
        public int networkMaximumSendSize; //초당 최고치를 기록한 전송 바이트.
        public int networkMaximumRecvSize; //초당 최고치를 기록한 수신 바이트
        public int networkMaximumTotalSize; //초당 전송,받은 데이터의 최대 크기.

        public int networkRecvPacketPerSecond; //초당 전송한 패킷
        public int networkSendPacketPerSecond; //초당 수신한 패킷
        public int networkTotalPacketPerSecond; //초당 전송 및 수신 패킷
        public int networkMaximumSendPacket; //초당 최고치를 기록한 전송패킷 수
        public int networkMaximumRecvPacket; //초당 최고치를 기록한 수신패킷 수
        public int networkMaximumTotalPacket; //초당 전송, 받은 데이터의 최대 개수.

    };

    class DashBoardClient
    {

        private TcpClient sock = null;
        private NetworkStream networkStream = null;
		
		
/// ////
        public DashBoardClient()
        {
            //Connecting(ipAddress);
        }
        ~DashBoardClient()
        {
            if (networkStream != null)
                networkStream.Close();

            if (sock != null)
                sock.Close();
        }
 ///////
		
        //접속 요청
        public void Connecting(string ipAddress)
        {
            try
            {
                sock = new TcpClient(ipAddress, 36555);
                networkStream = sock.GetStream();
            }
            catch (Exception e)
            {
                networkStream.Close();
                sock.Close();
                throw new Exception(e.Message);
            }
        }

        //데이터를 받아온다.
        public ResourceInfo Get_Resource_Data()
        {
            ResourceInfo serv_resource = new ResourceInfo();
            byte[] buffer = new byte[Marshal.SizeOf(serv_resource)];
			
			try
            {
                //서버로 부터 데이터를 받는다.
                networkStream.Read(buffer, 0, Marshal.SizeOf(serv_resource));
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
			networkStream.Close();
			sock.Close();
		}
    }
}

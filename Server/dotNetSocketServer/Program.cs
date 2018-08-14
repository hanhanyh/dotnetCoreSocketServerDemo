using System;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Text;
namespace dotNetSocketServer
{
    class Program
    {
        static void Main(string[] args)
        {
            Int32 port = 13000;
            IPAddress localadd = IPAddress.Any;
            TcpListener server = new TcpListener(localadd, port);
            server.Start();
            Byte[] bytes = new byte[256];
            String data = null;
            TcpClient client=null;
            try
            {
                while (true)
                {
                    Console.WriteLine("等待新的连接...");
                    client = server.AcceptTcpClient();
                    Console.WriteLine("连接成功！");
                    data = null;
                    NetworkStream nstream = client.GetStream();
                    int offset;
                    while ((offset = nstream.Read(bytes, 0, bytes.Length)) != 0)
                    {
                        data = System.Text.Encoding.UTF8.GetString(bytes, 0, offset);
                        Console.WriteLine("收到了：" + data);
                        byte[] msg = System.Text.Encoding.UTF8.GetBytes(data);
                        nstream.Write(msg, 0, msg.Length);
                        Console.WriteLine("发送了:{0}", data);
                    }
                }
            }
            catch (Exception ex)
            {
                client.Close();
                Console.WriteLine(ex.Message);
            }
            Console.WriteLine("服务器已停止.");
            Console.ReadLine();
          
        }
    }
}

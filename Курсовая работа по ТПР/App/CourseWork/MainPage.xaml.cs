using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Data;

namespace CourseWork
{
    public partial class MainPage : Page
    {
        // Таблицы с данными
        static DataTable main_table = new DataTable("main_table");
        static DataTable result_table = new DataTable("result_Table");
        // формат хранения чисел double в таблицах
        string doubleFormat = "0.####";

        // Выполняется при запуске программы
        public MainPage()
        {
            InitializeComponent();
            // Создание главной таблицы
            main_table.Columns.AddRange(new DataColumn[]
            {
                new System.Data.DataColumn("j",typeof(int)){ Caption = "j - Номер испытания"},
                new System.Data.DataColumn("i",typeof(string)) { Caption = "i - Номер заявки" },
                new System.Data.DataColumn("r",typeof(double)){ Caption = "r - Случайное число", AllowDBNull = true },
                new System.Data.DataColumn("-ln(r)",typeof(double)){ Caption = "-ln(r)", AllowDBNull = true },
                new System.Data.DataColumn("t",typeof(double)){ Caption = "t(i) = k1(-ln(r)) - Время между заявками", AllowDBNull = true },
                new System.Data.DataColumn("T",typeof(double)){ Caption = "T(i) = T(i-1) + t(i)- Момент поступления заявки", AllowDBNull = true },
                new System.Data.DataColumn("R",typeof(double)){ Caption = "R - Случайное число", AllowDBNull = true },
                new System.Data.DataColumn("-ln(R)",typeof(double)){ Caption = "-ln(R)", AllowDBNull = true },
                new System.Data.DataColumn("tau",typeof(double)){ Caption = "tau(i) = k1(-ln(r)) - Длительность обслуживания заявки", AllowDBNull = true },
                new System.Data.DataColumn("startSvc",typeof(double)){ Caption = "startSvc - Момент начала обслуживания", AllowDBNull = true },
                new System.Data.DataColumn("endSvc",typeof(double)){ Caption = "endSvc - Момент окончания обслуживания", AllowDBNull = true },
                new System.Data.DataColumn("svc",typeof(int)){ Caption = "svc - Заявка обслужена", AllowDBNull = true },
                new System.Data.DataColumn("ref",typeof(int)){ Caption = "ref - Отказ в обслуживании заявки", AllowDBNull = true }
            });
            // Создание таблицы с результатами
            result_table.Columns.AddRange(new System.Data.DataColumn[] {
                new System.Data.DataColumn("j",typeof(string)){Caption="j - Номер испытания"},
                new System.Data.DataColumn("N_rec",typeof(double)){Caption="N_rec - Поступило заявок"},
                new System.Data.DataColumn("N_svc",typeof(double)){Caption="N_svc - Обслужено заявок"},
                new System.Data.DataColumn("tau_sum",typeof(double)){Caption="tau_sum - Длительность обслуживания", AllowDBNull = true},
                new System.Data.DataColumn("tau_mid",typeof(double)){Caption="tau_mid - Среднее время обслуживания"},
                new System.Data.DataColumn("P",typeof(double)){Caption="P - вероятность обслуживания"},
                new System.Data.DataColumn("Q",typeof(double)){Caption="Q - вероятность отказа", AllowDBNull = true}
            });

            // Создание легенды
            List<string> colNames = new List<string>(main_table.Columns.Count);
            foreach (DataColumn col in main_table.Columns)
            {
                if (col.Caption != col.ColumnName)
                    colNames.Add(col.Caption);
            }
            foreach (DataColumn col in result_table.Columns)
            {
                colNames.Add(col.Caption);
            }
            // Вывод легенды
            legendListBox.ItemsSource = colNames;

            // Генерация и вывод данных таблиц
            SolveButtonClick(null, null);
            dataGrid_1.ColumnWidth = 50;
            dataGrid_2.ColumnWidth = 50;
            dataGrid_3.ColumnWidth = 50;
        }

        // Генерация данных для таблиц
        private void GenerateTableData(int J, int T_max, double l1, double l2)
        {
            // Проверки на корреткность аргументов
            if (J < 0) throw new ArgumentOutOfRangeException("J", "Значение данного аргумента не может быть меньше 0");
            if (T_max < 0) throw new ArgumentOutOfRangeException("T_max", "Значение данного аргумента не может быть меньше 0");
            if (l1 < 0) throw new ArgumentOutOfRangeException("l1", "Значение данного аргумента не может быть меньше 0");
            if (l2 < 0) throw new ArgumentOutOfRangeException("l2", "Значение данного аргумента не может быть меньше 0");

            // очистка значений таблиц
            main_table.Clear();
            result_table.Clear();

            // подсчёт и вывод k1 и k2
            double k1 = 1.0 / l1;
            double k2 = 1.0 / l2;
            k1_textBlock.Text = string.Format("k1 = {0}", k1.ToString(doubleFormat));
            k2_textBlock.Text = string.Format("k2 = {0}", k2.ToString(doubleFormat));

            // переменные, с помощью которых получаются случайные числа
            Random R = new Random();
            Random r = new Random();

            // временные переменные (обозначения см. в приложении 1)
            double t, T, cur_r, cur_R, ln_r, ln_R, tau, startSvc, endSvc, tau_sum, P, tau_mid_sum, N_rec_sum, N_svc_sum, P_sum, tau_mid;
            int svcCount, refCount, i;

            // переменные, использующиеся в результирующей таблице
            tau_mid_sum = N_rec_sum = N_svc_sum = P_sum = tau_mid = 0;
            
            // Все испытания
            for (int j = 1; j <= J; j++)
            {
                cur_R = R.Next(1, 100)/100.0;
                ln_R = -Math.Log(cur_R);
                tau_sum = cur_r = ln_r = startSvc = T = t = 0;
                endSvc = tau = k2 * ln_R;
                svcCount = 1;
                refCount = 0;

                // Первая строка в каждом испытании
                main_table.Rows.Add(new object[] { j, 1.ToString(), null, null, null, T.ToString(doubleFormat), cur_R.ToString(doubleFormat), ln_R.ToString(doubleFormat), tau.ToString(doubleFormat), startSvc.ToString(doubleFormat), endSvc.ToString(doubleFormat), svcCount, null});

                // Все остальные строки в каждом испытании
                cur_r = r.Next(1, 100) / 100.0;
                ln_r = -Math.Log(cur_r);
                t = k1 * ln_r;
                T += t;
                for (i = 1; T < T_max; i++)
                {
                    cur_r = r.Next(1, 100)/100.0;
                    cur_R = R.Next(1, 100)/100.0;
                    ln_r = -Math.Log(cur_r);
                    ln_R = -Math.Log(cur_R);
                    tau = k2 * ln_R;
                    // Если заявка обслужена
                    if (T > endSvc && T + tau <= T_max)
                    {
                        endSvc = T + tau;
                        svcCount++;
                        main_table.Rows.Add(new object[] { j, (i + 1).ToString(), cur_r.ToString(doubleFormat), ln_r.ToString(doubleFormat), t.ToString(doubleFormat), T.ToString(doubleFormat), cur_R.ToString(doubleFormat), ln_R.ToString(doubleFormat), tau.ToString(doubleFormat), T.ToString(doubleFormat), endSvc.ToString(doubleFormat), 1, null });
                    }
                    // если заявка не обслужена
                    else
                    {
                        refCount++;
                        tau = endSvc = 0;
                        main_table.Rows.Add(new object[] { j, (i + 1).ToString(), cur_r.ToString(doubleFormat), ln_r.ToString(doubleFormat), t.ToString(doubleFormat), T.ToString(doubleFormat), null, null, null, null, null, null, 1 });
                    }
                    tau_sum += tau;
                    t = k1 * ln_r;
                    T += t;
                }
                // расчёт и добавление значений для 
                // строк табл. 3 (result_table) и последних
                // строк для каждого испытания в табли. 1, 2 (main_table)
                tau_mid = tau_sum / svcCount;
                P = (double)svcCount/i;
                result_table.Rows.Add(new object[] { j.ToString(), i, svcCount, tau_sum.ToString(doubleFormat), tau_mid.ToString(doubleFormat), P.ToString(doubleFormat), (1.0-P).ToString(doubleFormat) });

                tau_mid_sum += tau_mid;
                N_rec_sum += i;
                N_svc_sum += svcCount;
                P_sum += P;
                main_table.Rows.Add(new object[] { j, "sum", null, null, null, null, null, null, tau_sum.ToString(doubleFormat), null, null, svcCount, refCount });
            }
            // последние две строки в табл. 3
            result_table.Rows.Add(new object[] { "sum", N_rec_sum, N_svc_sum, null, tau_mid_sum.ToString(doubleFormat), P_sum.ToString(doubleFormat), null });
            result_table.Rows.Add(new object[] { "mid", (N_rec_sum/J).ToString(doubleFormat), (N_svc_sum/J).ToString(doubleFormat), null, (tau_mid_sum/J).ToString(doubleFormat), (P_sum/J).ToString(doubleFormat), null });
        }

        // Обновляет значения DataGrid (вывод таблиц)
        private void RefreshTables()
        {
            dataGrid_1.ItemsSource = 
                (from row 
                 in main_table.AsDataView().ToTable("Table1", false, "j", "i", "r", "-ln(r)", "t", "T").AsEnumerable()
                 where row["i"].ToString()!="sum"
                 select row).AsDataView();

            dataGrid_2.ItemsSource = main_table.AsDataView().ToTable("Table2", false, "j", "i", "R", "-ln(R)", "tau", "startSvc", "endSvc", "svc", "ref").DefaultView;

            dataGrid_3.ItemsSource = result_table.DefaultView;

            NameOrCaption_SelectionChanged(NameOrCaption, null);
        }

        // Выполняется при нажатии на кнопку "Решить"
        private void SolveButtonClick(object sender, RoutedEventArgs e)
        {
            try
            {
                GenerateTableData(int.Parse(J_TextBox.Text), int.Parse(T_TextBox.Text), double.Parse(l1_TextBox.Text), double.Parse(l2_TextBox.Text));
                RefreshTables();
            }
            catch (System.FormatException e1)
            {
                MessageBox.Show(e1.Message, "Ошибка!");
            }
            catch (ArgumentOutOfRangeException e2)
            {
                MessageBox.Show(e2.Message, "Ошибка!");
            }
            catch (Exception e3) { }
        }

        private void NameOrCaption_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if(((ComboBoxItem)((ComboBox)sender).SelectedItem).Name.ToString() == "caption")
            {
                ChangeDataGridHeaders(main_table, dataGrid_1, 100);
                ChangeDataGridHeaders(main_table, dataGrid_2, 100);
                ChangeDataGridHeaders(result_table, dataGrid_3, 100);
                if (legendListBox != null)
                {
                    legendListBox.Visibility = Visibility.Hidden;
                    legendListBox.Width = 0;
                    legendListBox.Height = 0; 
                }
            }
            else
            {
                ChangeDataGridHeaders(main_table, dataGrid_1, 50, true);
                ChangeDataGridHeaders(main_table, dataGrid_2, 50, true);
                ChangeDataGridHeaders(result_table, dataGrid_3, 50, true);
                if (legendListBox != null)
                {
                    legendListBox.Visibility = Visibility.Visible;
                    legendListBox.Height = 364;
                    legendListBox.Width = 312;
                }
            }
        }

        private void ChangeDataGridHeaders(DataTable dt, DataGrid dg, int width, bool toName = false)
        {
            if(dt!=null && dg!=null)
                if(!toName)
                {
                    foreach (DataGridColumn dgcol in dg.Columns)
                    {
                        dgcol.Header = dt.Columns[dgcol.Header.ToString()].Caption.ToString();
                        dgcol.Width = width;
                    }
                }
                else
                {
                    foreach (DataGridColumn dgcol in dg.Columns)
                    {
                        foreach (DataColumn col in dt.Columns)
                        {
                            if (dgcol.Header.ToString() == col.Caption.ToString())
                            {
                                dgcol.Header = col.ColumnName;
                                break;
                            }
                        }
                        dgcol.Width = width;
                    }
                }
        }
    }
}